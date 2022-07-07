/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:58:02 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/22 15:58:04 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leaks.h"

static void         *malloc_list[1024];
static unsigned int list_size = 0;

static void remove_from_list(void *ptr) {
    int i;

    i = 0;
    while (i < list_size && ptr != malloc_list[i])
        ++i;
    while (malloc_list[i + 1])
    {
        malloc_list[i] = malloc_list[i + 1];
        ++i;
    }
    malloc_list[i] = NULL;
    --list_size;
}

static void add_to_list(void *ptr) {
    if (list_size >= 1023)
    {
        dprintf(2, "\e[31mLEAKS.ERROR: too much malloc\e[0m\n");
        exit (1);
    }
    malloc_list[list_size] = ptr;
    ++list_size;
}

void *malloc(size_t size) {

    void *(*libc_malloc)(size_t size) = (void *(*)(size_t)) dlsym(RTLD_NEXT, "malloc");
    void *p = libc_malloc(size);
    if (!p)
        return (NULL);
    add_to_list(p);
    return (p);
}

void free(void *ptr) {
    void *(*libc_free)(void *ptr) = (void *(*)(void *)) dlsym(RTLD_NEXT, "free");
    libc_free(ptr);
    remove_from_list(ptr);
}

void check_leaks(void) {
    if (list_size > 0)
    {
        dprintf(2, "\e[31mLEAKS!\n\e[0m");
        int i = 0;
        while(malloc_list[i])
        {
            dprintf(2, "\e[31m%d: [%p]\n\e[0m", i, malloc_list[i]);
            ++i;
        }
    }
    else
        dprintf(2, "\e[32mNO LEAKS :D\n\e[0m");
}

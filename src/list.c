#include "interface.h"

/* List data type */

Wchar_Array_List* init_list(const wchar_t** waa) 
{
    Wchar_Array_List* wal = (Wchar_Array_List*)malloc(sizeof(Wchar_Array_List));
    wal->size = 0;
    wal->list = NULL;
    if (waa != NULL) 
    {
        int count = 0;
        while (waa[count] != NULL)
        {
            count++;
        }
        wal->list = (wchar_t**)malloc(count * sizeof(wchar_t*));
        for (int i = 0; i < count; i++) 
        {
            wal->list[i] = wcsdup(waa[i]);
        }
        wal->size = count;
    }
    return wal;
}

void free_list(Wchar_Array_List* wal) 
{
    if (wal == NULL)
    {
        return;
    }
    for (int i = 0; i < wal->size; i++) 
    {
        free(wal->list[i]);
    }
    free(wal->list);
    free(wal);
}

int add_item(Wchar_Array_List* wal, const wchar_t* wa) 
{
    if (wal == NULL || wa == NULL)
    {
        return -1;
    }
    wal->list = (wchar_t**)realloc(wal->list, (wal->size + 1) * sizeof(wchar_t*));
    wal->list[wal->size] = wcsdup(wa);
    wal->size++;
    return wal->size - 1;
}

int update_item(Wchar_Array_List* wal, const wchar_t* wa, int i) 
{
    if (wal == NULL || wa == NULL || i < 0 || i >= wal->size)
    {
        return -1;
    }
    free(wal->list[i]);
    wal->list[i] = wcsdup(wa);
    return i;
}

int insert_item(Wchar_Array_List* wal, const wchar_t* wa, int n) 
{
    if (wal == NULL || wa == NULL || n < 0 || n > wal->size)
    {
        return -1;
    }
    wal->list = (wchar_t**)realloc(wal->list, (wal->size + 1) * sizeof(wchar_t*));
    memmove(&wal->list[n + 1], &wal->list[n], (wal->size - n) * sizeof(wchar_t*));
    wal->list[n] = wcsdup(wa);
    wal->size++;
    return n;
}

int swap_items(Wchar_Array_List* wal, int i, int j) 
{
    if (wal == NULL || i < 0 || i >= wal->size || j < 0 || j >= wal->size)
    {
        return -1;
    }
    wchar_t* temp = wal->list[i];
    wal->list[i] = wal->list[j];
    wal->list[j] = temp;
    return 0;
}

int delete_item(Wchar_Array_List* wal, int n) 
{
    if (wal == NULL || n < 0 || n >= wal->size)
    {
        return -1;
    }
    free(wal->list[n]);
    memmove(&wal->list[n], &wal->list[n + 1], (wal->size - n - 1) * sizeof(wchar_t*));
    wal->size--;
    return 0;
}

void print_list(Wchar_Array_List* wal) 
{
    setlocale(LC_ALL, "");
    if (wal == NULL)
    {
        return;
    }
    for (int i = 0; i < wal->size; i++) 
    {
        wprintf(L"%ls\n", wal->list[i]);
    }
}

char* get_item(Wchar_Array_List* wal, int n) 
{
    if (wal == NULL || n < 0 || n >= wal->size)
    {
        return NULL;
    }
    int size = wcstombs(NULL, wal->list[n], 0);
    char* result = (char*)malloc((size + 1) * sizeof(char));
    wcstombs(result, wal->list[n], size + 1);
    return result;
}
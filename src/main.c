#include "interface.h"

void print_dwstring(Dynamic_Wide_String* dws) 
{
    wprintf(L"String: %ls\n", dws->data);
    wprintf(L"Size: %d\n", dws->size);
}

int main() 
{
    setlocale(LC_ALL, "");  // Set locale for wide character output

    // Test init_dwstring
    Dynamic_Wide_String* dws = init_dwstring(L"Hello 世界 🔥");
    wprintf(L"After initialization:\n");
    print_dwstring(dws);

    // Test append_to_dwstring
    append_to_dwstring(dws, L" How are you?");
    wprintf(L"\nAfter appending:\n");
    print_dwstring(dws);

    // Test prepend_to_dwstring
    prepend_to_dwstring(dws, L"Greetings! ");
    wprintf(L"\nAfter prepending:\n");
    print_dwstring(dws);

    // Test replace_dwstring
    replace_dwstring(dws, L"This is a new string.");
    wprintf(L"\nAfter replacing:\n");
    print_dwstring(dws);

    // Test substitute_in_dwstring
    substitute_in_dwstring(dws, L"new", L"modified");
    wprintf(L"\nAfter substitution:\n");
    print_dwstring(dws);

    // Test free_dwstring
    free_dwstring(dws);
    wprintf(L"\nDynamic_Wide_String freed.\n");

    return 0;
}
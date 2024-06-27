#include "interface.h"

int main()
{
    if (is_sqlite_installed())
    {
        if (file_exists("kv.db")) 
        {
            printf("\nTable already exists.\n");
        }
        else
        {
            create_key_value_table("kv");
            insert_key_value_pair("kv", "John", "Plumber");
            insert_key_value_pair("kv", "Bill", "Firefighter");
            insert_key_value_pair("kv", "Susan", "Engineer");
        }
        char *v0 = select_all_pairs("kv");
        char *v1 = select_all_keys("kv");
        char *v2 = select_all_values("kv");
        printf("\n%s\n%s\n%s\n", v0, v1, v2);
        delete_key_value_pair("kv", "Bill");
        bool v3 = table_contains_key("kv", "Bill");
        char *v4 = select_all_keys("kv");
        char *v5 = select_all_values("kv");
        char *v6 = select_row_from_key("kv", "John");
        char *v7 = select_value_from_key("kv", "Susan");
        printf("%d\n%s\n%s\n%s\n%s\n", v3, v4, v5, v6, v7);
    }
    else
    {
        printf("Sqlite3 is not installed.\n");
    }
    return 0;
}
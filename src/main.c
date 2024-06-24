#include "interface.h"

int main() 
{
    const char* s1 = "hello";
    const char* s2 = "hello";
    const char* s3 = "world";
    
    printf("Comparing '%s' and '%s':\n", s1, s2);
    printf("Length comparison: %s\n", compare_lengths(s1, s2) ? "Equal" : "Not equal");
    printf("First char comparison: %s\n", compare_first_char(s1, s2) ? "Equal" : "Not equal");
    printf("Full string comparison: %s\n", compare_full_strings(s1, s2) ? "Equal" : "Not equal");
    printf("Optimized comparison: %s\n\n", compare_optimized(s1, s2) ? "Equal" : "Not equal");
    
    printf("Comparing '%s' and '%s':\n", s1, s3);
    printf("Length comparison: %s\n", compare_lengths(s1, s3) ? "Equal" : "Not equal");
    printf("First char comparison: %s\n", compare_first_char(s1, s3) ? "Equal" : "Not equal");
    printf("Full string comparison: %s\n", compare_full_strings(s1, s3) ? "Equal" : "Not equal");
    printf("Optimized comparison: %s\n", compare_optimized(s1, s3) ? "Equal" : "Not equal");
    
    return 0;
}
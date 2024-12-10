#define TITLE_LEN 31
#define AUTHOR_LEN 31
#define DESIGN_LEN 31
#include <stdio.h>
#include <stdlib.h>
struct catalog_item {
int stock_number;
double price;
int item_type;
union {
struct {
char title[TITLE_LEN+1];
char author[AUTHOR_LEN+1];
int num_pages;
} book;
struct {
char design[DESIGN_LEN+1];
} mug;
struct {
char design[DESIGN_LEN+1];
int colors;
int sizes;
} shirt;
} item;
}; 
int main()
{
    struct catalog_item catalog[3] = {
        // First item: Book
        {
            101,  // stock_number
            19.99,  // price
            1,  // item_type (assuming 1 represents a book)
            .item.book = {
                ""The Great Gatsby"",  // title
                ""F. Scott Fitzgerald"",  // author
                180  // num_pages
            }
        },
        // Second item: Mug
        {
            102,  // stock_number
            9.99,  // price
            2,  // item_type (assuming 2 represents a mug)
            .item.mug = {
                ""Checkerboard""  // design
            }
        },
        // Third item: Shirt
        {
            103,  // stock_number
            24.99,  // price
            3,  // item_type (assuming 3 represents a shirt)
            .item.shirt = {
                ""Cool Graphic"",  // design
                5,  // colors
                3  // sizes
            }
        }
    };
    
    printf(""%s\n"", catalog[1].item.mug.design);
    printf(""%d\n"", catalog[1].item.shirt.colors);
    printf(""%s\n"", catalog[1].item.shirt.design);
    //catalog[1].item.book.title = ""Mistborn""; //this doesn't work (wont compile)
    strcpy(catalog[1].item.book.title, ""Mistborn"");
    printf(""%s\n"", catalog[1].item.shirt.design);
    

    return 0;
}"

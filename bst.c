
#include "DS.h"
#include <stdio.h>
#include <stdlib.h>

/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Оруулахдаа хоёртын хайлтын модны зарчмаар оруулах бөгөөд оруулсан
  байрлалаас дээшхи өвөг эцгийн `len`, `height` утгууд өөрчлөгдөнө.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
 */
void bs_put(BST *ptree, int x)
{
    ptree->root = insertNode(ptree->root, x);
}

/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *bs_get(const BST *ptree, int x)
{
    Elm *p = ptree->root;

    while (p != NULL) {
        if (p->x == x)
            return p;

        if (x < p->x)
            p = p->L;
        else
            p = p->R;
    }

    return NULL;
}

/*
  Устгах функц: ХХМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
 */
void bs_del(BST *ptree, int x)
{
    ptree->root = deleteNode(ptree->root, x);
}

/*
  Хамгийн багыг устгах функц: ХХМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
 */
int bs_delMin(BST *ptree)
{
    Elm *p = minNode(ptree->root);
    int x = p->x;

    ptree->root = deleteMinNode(ptree->root);

    return x;
}

/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void bs_inorder(const BST *ptree)
{
    printInorder(ptree->root);
}

/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */
int bs_rank(const BST *ptree, int x)
{
    Elm *p = ptree->root;
    int count = 0;

    while (p != NULL) {
        if (x < p->x) {
            p = p->L;
        } else {
            count += getLen(p->L) + 1;
            p = p->R;
        }
    }

    return count;
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int bs_size(const BST *ptree, int x)
{
    Elm *p = bs_get(ptree, x);

    if (p == NULL)
        return -1;

    return p->len;
}

/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_floor(const BST *ptree, int x)
{
    Elm *p = ptree->root;
    Elm *result = NULL;

    while (p != NULL) {
        if (p->x == x)
            return p;

        if (p->x > x) {
            p = p->L;
        } else {
            result = p;
            p = p->R;
        }
    }

    return result;
}

/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_ceiling(const BST *ptree, int x)
{
    Elm *p = ptree->root;
    Elm *result = NULL;

    while (p != NULL) {
        if (p->x == x)
            return p;

        if (p->x < x) {
            p = p->R;
        } else {
            result = p;
            p = p->L;
        }
    }

    return result;
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */
int bs_height(const BST *ptree, int x)
{
    Elm *p = bs_get(ptree, x);

    if (p == NULL)
        return -1;

    return p->height;
}

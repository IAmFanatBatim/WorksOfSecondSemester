#include "string_.c"
#include "assert.h"

void test_strlen_commonString() {
    char *s = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_hasControlCharacters() {
    char *s = "\t\"Hello!\"";
    assert(strlen_(s) == 9);
}
void test_strlen_hasEscapingCharacters() {
    char *s = "\\tHello!\\t";
    assert(strlen_(s) == 10);
}
void test_strlen_moreMemoryThanNeed() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_emptyString() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_() {
    test_strlen_commonString();
    test_strlen_hasControlCharacters();
    test_strlen_hasEscapingCharacters();
    test_strlen_moreMemoryThanNeed();
    test_strlen_emptyString();
}

void test_find_oneInclusion() {
    char *s = "Hello!";
    assert(find(s, s+strlen_(s), 'e') == s+1);
}
void test_find_severalInclusions() {
    char *s = "Hello!";
    assert(find(s, s+strlen_(s), 'l') == s+2);
}
void test_find_noInclusions() {
    char *s = "Hello!";
    assert(find(s, s+strlen_(s), 'a') == s+6);
}
void test_find_cutSearchArea() {
    char *s = "Hello!";
    assert(find(s, s+strlen_(s)-3, 'o') == s+3);
}
void test_find_emptySearchArea() {
    char *s = "Hello!";
    assert(find(s, s, 'H') == s);
}
void test_find() {
    test_find_oneInclusion();
    test_find_severalInclusions();
    test_find_noInclusions();
    test_find_cutSearchArea();
    test_find_emptySearchArea();
}

void test_findNonSpace_foundWithSpaceBefore() {
    char *s = "  Hello!";
    assert(findNonSpace(s) == s+2);
}
void test_findNonSpace_foundWithSpaceCharactersBefore() {
    char *s = "\t \nHello!";
    assert(findNonSpace(s) == s+3);
}
void test_findNonSpace_notFound() {
    char *s = "\t \n\r";
    assert(findNonSpace(s) == s+4);
}
void test_findNonSpace_emptySearchArea() {
    char *s = "Hello!";
    assert(findNonSpace(s) == s);
}
void test_findNonSpace() {
    test_findNonSpace_foundWithSpaceBefore();
    test_findNonSpace_foundWithSpaceCharactersBefore();
    test_findNonSpace_notFound();
    test_findNonSpace_emptySearchArea();
}

void test_findSpace_foundSpace() {
    char *s = "H e l l o !\t";
    assert(findSpace(s) == s+1);
}
void test_findSpace_foundSpaceCharacter() {
    char *s = "Hello!\t";
    assert(findSpace(s) == s+6);
}
void test_findSpace_notFound() {
    char *s = "Hello!";
    assert(findSpace(s) == s+6);
}
void test_findSpace_emptySearchArea() {
    char *s = "";
    assert(findSpace(s) == s);
}
void test_findSpace() {
    test_findSpace_foundSpace();
    test_findSpace_foundSpaceCharacter();
    test_findSpace_notFound();
    test_findSpace_emptySearchArea();
}

void test_findNonSpaceReverse_foundWithSpaceBefore() {
    char *s = "Hello!  ";
    assert(findNonSpaceReverse(s+strlen_(s)-1, s-1) == s+5);
}
void test_findNonSpaceReverse_foundWithSpaceCharactersBefore() {
    char *s = "Hello!\t\n";
    assert(findNonSpaceReverse(s+strlen_(s)-1, s-1) == s+5);
}
void test_findNonSpaceReverse_notFound() {
    char *s = "\t \n\r";
    assert(findNonSpaceReverse(s+strlen_(s)-1, s-1) == s-1);
}
void test_findNonSpaceReverse_cutSearchArea() {
    char *s = "Hello!\t\n";
    assert(findNonSpaceReverse(s+strlen_(s)-1, s+5) == s+5);
}
void test_findNonSpaceReverse_emptySearchArea() {
    char *s = "";
    assert(findNonSpaceReverse(s+strlen_(s)-1, s-1) == s-1);
}
void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_foundWithSpaceBefore();
    test_findNonSpaceReverse_foundWithSpaceCharactersBefore();
    test_findNonSpaceReverse_notFound();
    test_findNonSpaceReverse_cutSearchArea();
    test_findNonSpaceReverse_emptySearchArea();
}

void test_findSpaceReverse_foundSpace() {
    char *s = "Hello World!";
    assert(findSpaceReverse(s+strlen_(s)-1, s-1) == s+5);
}
void test_findSpaceReverse_foundSpaceCharacter() {
    char *s = "Hello\tWorld!";
    assert(findSpaceReverse(s+strlen_(s)-1, s-1) == s+5);
}
void test_findSpaceReverse_notFound() {
    char *s = "Hello!";
    assert(findSpaceReverse(s+strlen_(s)-1, s-1) == s-1);
}
void test_findSpaceReverse_cutSearchArea() {
    char *s = "Hello World!";
    assert(findSpaceReverse(s+strlen_(s)-1, s+7) == s+7);
}
void test_findSpaceReverse_emptySearchArea() {
    char *s = "";
    assert(findSpaceReverse(s+strlen_(s)-1, s-1) == s-1);
}
void test_findSpaceReverse() {
    test_findSpaceReverse_foundSpace();
    test_findSpaceReverse_foundSpaceCharacter();
    test_findSpaceReverse_notFound();
    test_findSpaceReverse_cutSearchArea();
    test_findSpaceReverse_emptySearchArea();
}

void test_strcmp_areEqual() {
    char *lhs = "Hello World!";
    char *rhs = "Hello World!";
    assert(strcmp(lhs, rhs) == 0);
}
void test_strcmp_lhsEarlierInHalf() {
    char *lhs = "Hello World!";
    char *rhs = "Hi World!";
    assert(strcmp(lhs, rhs) == -4);
}
void test_strcmp_lhsLaterInHalf() {
    char *lhs = "Hello World!";
    char *rhs = "Goodbye World!";
    assert(strcmp(lhs, rhs) == 1);
}
void test_strcmp_lhsEarlierCutOff() {
    char *lhs = "Hell";
    char *rhs = "Hello World!";
    assert(strcmp(lhs, rhs) == -111);
}
void test_strcmp_lhsLaterCutOff() {
    char *lhs = "Hello World!";
    char *rhs = "Hello World!";
    assert(strcmp(lhs, rhs) == 111);
}
void test_strcmp() {
    test_strcmp_areEqual();
    test_strcmp_lhsEarlierInHalf();
    test_strcmp_lhsLaterInHalf();
    test_strcmp_lhsEarlierCutOff();
    test_strcmp_lhsLaterCutOff();
}

void test() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
}

int main () {
    test();
    printf("All is okay\n");
    printf("%d", 'o');
    return 0;
}
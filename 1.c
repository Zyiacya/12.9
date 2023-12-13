#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findWord(char* givenWord, char* article) {
    // 将给定单词和文章转换为小写，以进行不区分大小写的匹配
    char lowerGivenWord[100];
    char lowerArticle[1000];

    strcpy(lowerGivenWord, givenWord);
    strcpy(lowerArticle, article);

    for (int i = 0; lowerGivenWord[i]; i++) {
        lowerGivenWord[i] = tolower(lowerGivenWord[i]);
    }

    for (int i = 0; lowerArticle[i]; i++) {
        lowerArticle[i] = tolower(lowerArticle[i]);
    }

    // 初始化计数和位置变量
    int count = 0;
    int position = -1;

    // 找到第一个匹配的位置
    char* firstOccurrence = strstr(lowerArticle, lowerGivenWord);

    while (firstOccurrence != NULL) {
        // 如果找到了匹配，增加计数
        count++;

        // 更新位置变量
        position = firstOccurrence - lowerArticle;

        // 继续查找下一个匹配
        firstOccurrence = strstr(firstOccurrence + 1, lowerGivenWord);
    }

    // 输出结果
    if (count > 0) {
        printf("%d %d\n", count, position);
    } else {
        printf("-1\n");
    }
}

int main() {
    // 读取输入的给定单词和文章
    char givenWord[100];
    char article[1000];

    fgets(givenWord, sizeof(givenWord), stdin);
    fgets(article, sizeof(article), stdin);

    // 去除字符串末尾的换行符
    givenWord[strcspn(givenWord, "\n")] = 0;
    article[strcspn(article, "\n")] = 0;

    // 调用函数查找单词并输出结果
    findWord(givenWord, article);

    return 0;
}
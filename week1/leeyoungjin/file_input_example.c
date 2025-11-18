#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp; // 파일 포인터 선언

    // 파일 열기: "data.txt" 파일을 쓰기 모드("w")로 엽니다.
    fp = fopen("input.txt", "");

    //  파일 열기 실패 시 에러 처리 필수! (파일이 없거나 권한이 없을 때)
    if (fp == NULL)
    {
        // 실패 처리 코드 (예: 에러 메시지 출력 후 종료)
    }
    return 0;
}
// aa
// aa
// aa
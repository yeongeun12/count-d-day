#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

//현재 시간 가져오는 함수
time_t now_date()
{
	time_t now; //변수 now가 초단위로 표현되도록 함

	time(&now); //현재 시간을 now에  저장

	return now; //현재 시간을 반환
}

//입력된 날짜까지 남은 일수 계산하는 함수
int countdown(int YY, int MM, int DD)
{
	struct tm d_day; //날짜 저장할 구조체 선언
	d_day.tm_year = YY - 1900; //입력된 연도 저장, 1900년을 기준으로 함
	d_day.tm_mon = MM - 1; //입력된 월을 저장, 0부터 시작하므로 -1
	d_day.tm_mday = DD; //입력된 day를 저장
	d_day.tm_hour = 0; //시간을 0으로 설정
	d_day.tm_min = 0; //분을 0으로 설정
	d_day.tm_sec = 0; //초를 0으로 설정

	time_t future_date = mktime(&d_day); //입력한 날짜를 mktime()을 통해 초단위로 변환
	time_t now = now_date(); //현재 날짜 가져오기

	double gap = difftime(future_date, now); //입력된 날짜와 현재 날짜의 차를 초단위로 계산
	int result = (int)(gap / (60 * 60 * 24)); //초단위를 day로 변환

	return result; //남은 일수 반환
}

//입력된 날짜로부터 지난 일수 계산하는 함수
int duration(int YY, int MM, int DD)
{
	struct tm enter_d_day; //입력된 날짜 저장할 구조체 enter_d_day선언
	enter_d_day.tm_year = YY - 1900; //입력된 연도 저장, 1900년을 기준으로 함
	enter_d_day.tm_mon = MM - 1; //입력된 월을 저장, 0부터 시작하므로 -1
	enter_d_day.tm_mday = DD; //입력된 day를 저장
	enter_d_day.tm_hour = 0; //시간을 0으로 설정
	enter_d_day.tm_min = 0; //분을 0으로 설정
	enter_d_day.tm_sec = 0; //초를 0으로 설정

	time_t past_d_day = mktime(&enter_d_day); //입력한 날짜를 mktime()을 통해 초단위로 변환
	time_t now = now_date(); //현재 날짜 가져오기

	double gap = difftime(now, past_d_day); //입력된 날짜와 현재 날짜의 차를 초단위로 계산
	int result = (int)(gap / (60 * 60 * 24)); //초단위를 day로 변환

	return result; //지난 일수 반환
}

int main()
{
	int year, month, day; //연도,월,일 변수 선언

	printf("Choose \"countdown\" or \"duration\": "); //두 기능 중 하나 선택 안내
	char choice[100]; //선택된 문자열 저장할 변수 선언
	scanf("%s", choice); //두 기능 중 하나 선택 입력 받기

	if (strcmp(choice, "countdown") == 0) //countdown 선택 시
	{
		printf("Enter the date(YYYY/MM/DD): "); //날짜 입력하시오 출력
		scanf("%d/%d/%d", &year, &month, &day); //날짜 입력 받기
		printf("D-%d", countdown(year, month, day)); //남은 일수 출력
	}
	else if (strcmp(choice, "duration") == 0) //duration 선택 시
	{
		printf("Enter the date(YYYY/MM/DD): "); //날짜 입력하시오 출력
		scanf("%d/%d/%d", &year, &month, &day); //날짜 입력 받기
		printf("D+%d", duration(year, month, day)); //지난 일수 출력
	}
	else //잘못 입력한 경우
	{
		printf("Enter again"); //다시 입력하시오 출력
	}
	return 0; //종료
}

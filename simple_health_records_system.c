#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct healthProfile	{
	char fName[20];
	char lName[20];
	char gender[6];
	double rHeight;
	double rWeight;
	char bDate[11];
};

void printIt(struct healthProfile hP);
void Age(struct healthProfile hP);
void BMI(struct healthProfile hP);

void main()	{
	char height[10];
	char weight[10];
	char *e = NULL;
	struct healthProfile hP;
	
	printf("Enter first name: ");
	fgets(hP.fName, sizeof(hP.fName), stdin);
	
	printf("Enter last name: ");
	fgets(hP.lName, sizeof(hP.lName), stdin);
	
	printf("Enter gender: ");
	fgets(hP.gender, sizeof(hP.gender), stdin);
	
	printf("Enter height in inches: ");
	fgets(height, sizeof(height), stdin);
	hP.rHeight = strtol(height, &e, 10);
	
	printf("Enter weight in pounds: ");
	fgets(weight, sizeof(weight), stdin);
	hP.rWeight = strtol(weight, &e, 10);
	
	printf("Enter birth date in MM/DD/YYYY format: ");
	fgets(hP.bDate, sizeof(hP.bDate), stdin);
	
	printIt(hP);
	Age(hP);
	BMI(hP);
}

void printIt(struct healthProfile hP)	{
	printf("\tFirst-Name:\t%s", hP.fName);
	printf("\tLast-Name:\t%s", hP.lName);
	printf("\tGender: \t%s", hP.gender);
	printf("\tHeight: \t%.2f\n", hP.rHeight);
	printf("\tWeight: \t%.2f\n", hP.rWeight );
	printf("\tDOB: \t\t%s\n", hP.bDate);
}


void BMI(struct healthProfile hP)	{
	float bmi = (hP.rWeight * 703)/(hP.rHeight * hP.rHeight);
	
	printf("\tyour BMI is: %.2f\n\n", bmi);
	printf("BMI VALUES\n");
	printf("Underweigt: \tless than 18.5\n");
	printf("Normal: \tbetween 18.5 and 24.9\n");
	printf("Overweight: \tbetween 15 and 29.9\n");
	printf("Obese: \t30 or greater\n\n");
}

void Age(struct healthProfile hP)	{
	char *token;
	int MM;
	int DD;
	int YY;
	int currentYY;
	
	token = strtok(hP.bDate, "/\n\0");

	int i = 0;
	while(token != NULL)	{
		
		if(i == 0)	{
			MM = atoi(token);
			i++;
		}
		else if(i == 1)	{
			DD =  atoi(token);
			i++;
		}
		else if(i == 2){
			YY =  atoi(token);
		}	
		token = strtok(NULL, "/\n\0");
	}
	
	time_t currentT;
	if(time(&currentT) != (time_t)(-1))	{
		struct tm * myTime = localtime(&currentT);
		if(myTime)	{
			char year[5];
			if(strftime(year, sizeof year, "%Y", myTime))	{
				currentYY = atoi(year);
			}
		}
	}
	
	int age = currentYY - YY;
	int maxRate = 220 - age;
	double targetRate = maxRate * (.65);	
	
	printf("\tAge: \t%d\n", age);
	printf("\tMax Heart Rate: \t%d\n", maxRate);
	printf("\tTarget Heart Rate: \t%.2f\n", targetRate);
}


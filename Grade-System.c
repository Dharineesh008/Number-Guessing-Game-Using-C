#include<stdio.h>
#include<string.h>
#include<time.h>
float getgradepoints(float marks){
    if(marks>90) return 10;
    else if(marks>80) return 9;
    else if(marks>70) return 8;
    else if(marks>60) return 7;
    else if(marks>50) return 6;
    else if(marks>45) return 5;
    else if(marks>39) return 4;
    else return 0;
}
char *getGrade(float marks){
    if(marks>90) return "Grade: O (Outstanding)";
    else if(marks>=80) return "Grade: A+ (Excellent)";
    else if(marks>=70) return "Grade: A (Very Good)";
    else if(marks>=60) return "Grade: B+ (Good)";
    else if(marks>=50) return "Grade: B (Above Average)";
    else if(marks>=45) return "Grade: C (Average)";
    else return "F (Fail)";
}
void printRow(FILE *f, char *subject, int credit, float marks, float gp, char *grade){
    printf("%-20s %7d %6.1f %5.1f %s\n",subject,credit,marks,gp,grade);
    fprintf(f,"%-20s %7d %6.1f %5.1f %s\n",subject,credit,marks,gp,grade);
}
int main(){
    int n;
    char studentname[100];
    printf("----CBCS Grade Calculator----\n");
    printf("Enter student Name:\n");
    scanf("%[^\n]",studentname);
    printf("Enter number of Subjects:\n");
    scanf("%d",&n);
    char subjects[n][50];
    float marks[n];
    int credits[n];
    for(int i=0;i<n;i++){
        printf("Enter Subject Name:\n");
        scanf(" %[^\n]",subjects[i]);
        printf("Enter credits for %s:\n",subjects[i]);
        scanf("%d",&credits[i]);
        printf("Enter the marks you scored for %s\n",subjects[i]);
        scanf("%f",&marks[i]);
    }
    FILE *fp=fopen("grades.txt","w");
    if(fp==NULL){
        printf("Error on opening the File!!!");
        return 1;
    }
    time_t t=time(NULL);
    struct tm *tm_info=localtime(&t);
    char timeStr[30];
    strftime(timeStr,sizeof(timeStr),"%d-%m-%Y %H:%M:%S",tm_info);
    printf("\n=====================================================\n");
    printf("Student: %s \n",studentname);
    printf("Date: %s\n",timeStr);
    printf("\n=====================================================\n");
    printf("%-20s %7s %6s %5s %s\n","Subject","Credits","Marks","GP","Grade");
    printf("\n=====================================================\n");
    fprintf(fp,"\n=====================================================\n");
    fprintf(fp,"Student: %s \n",studentname);
    fprintf(fp,"Date: %s\n",timeStr);
    fprintf(fp,"\n=====================================================\n");
    fprintf(fp,"%-20s %7s %6s %5s %s\n","Subject","Credits","Marks","GP","Grade");
    fprintf(fp,"\n=====================================================\n");
    int TotalCredits=0,failcount=0;
    float totalWeighted=0;
    for(int i=0;i<n;i++){
        float gp=getgradepoints(marks[i]);
        printRow(fp,subjects[i],credits[i],marks[i],gp,getGrade(marks[i]));
        totalWeighted+=gp*credits[i];
        TotalCredits+=credits[i];
        if(gp==0) failcount++;
    }
    float cgpa = totalWeighted/TotalCredits;
    printf("\n=====================================================\n");
    printf("Total Credits: %d\n",TotalCredits);
    printf("CGPA: %2.f/10.00\n",cgpa);
    printf("Results: %s \n",failcount==0? "PASS": "FAIL (Arrear in subjects/s)");
    printf("\n=====================================================\n");
    if(failcount>0)
    printf("Arrears: %dsubjects(s)\n",failcount);
    
    fprintf(fp,"\n=====================================================\n");
    fprintf(fp,"Total Credits: %d\n",TotalCredits);
    fprintf(fp,"CGPA: %2.f/10.00\n",cgpa);
    fprintf(fp,"Results: %s \n",failcount==0? "PASS": "FAIL (Arrear in subjects/s)");
    if(failcount>0)
    fprintf(fp,"Arrears: %dsubjects(s)\n",failcount);
    fclose(fp);
    printf("results are saved on grades.txt\n");
    return 0;
    

}

#include <stdio.h>

int main()
{
    int y, m, d, days, n; 
    char buf[100],c;

    printf("Input year,month and date separated white space.\n");
    for(;;){ 
        fgets(buf, 100, stdin);
		    n = sscanf(buf,"%d %d %d %c", &y, &m, &d, &c);
        if(n == 3) {
            break;
        }else{
            printf("Error. Input like [1999 5 5].\n");
            return 0;
        }
    }

    printf("year:%d month:%d day:%d\n",y,m,d);
    if(m < 3){
        y--;
        m += 12;
    }
    days = 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 428;

    if(days < 0){
        printf("Error: days < 0.");
		return 0;
    }

    switch (days % 7){
    case 0 :
        printf("Sunday\n");
        break;
    case 1 :
        printf("Monday\n");
        break;
    case 2 :
        printf("Tuesday\n");
        break;
    case 3 :
        printf("Wedneday\n");
        break;
    case 4 :
        printf("Thursday\n");
        break;
    case 5 :
        printf("Friday\n");
        break;
    case 6 :
        printf("Saturday\n");
        break;
    }

    return 0;
}

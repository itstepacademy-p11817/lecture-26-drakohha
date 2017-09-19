#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int string_to_number(const char* str) {
	int temp = 0;
	int i = 0;
	int sign = 0; // знак числа 0- положительное, 1 - отрицательное
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (str[i] >= 0x30 && str[i] <= 0x39)
	{
		temp = temp + (str[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);


}

char* number_to_string(char* str, int num) {
	
	char  t, *temp;
	int i, k;
	int sign = 0;
	i = 0;
	k = num;
	if (k<0)
	{
		sign = 1;
		k = -k;
	}
	do {
		t = k % 10;
		k = k / 10;
		str[i] = t | 0x30;
		i++;
	} while (k>0);
	if (sign == 1)
	{
		str[i] = '-';
		i++;
	}
	temp = new char[i];
	k = 0;
	i--;
	while (i >= 0) {
		temp[k] = str[i];
		i--; k++;
	}
	temp[k] = '\0';
	return temp;
}


void upper_case(char* str) {

	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') str[i] += 'A' - 'a';
		if (str[i] >= 'а' && str[i] <= 'я') str[i] += 'А' - 'А';
	}
}

void lower_case(char* str) {

	for (int i = 0; i<strlen(str) ; i++)
	{
		if (str[i]>='A' && str[i]<='Z') str[i] += 'z' - 'Z';
		if (str[i]>='А' && str[i]<='Я') str[i] += 'я' - 'Я';
	}

}

int fun_kol_slov(char* str_5, char* str) {
	int id = 0;
	const char* str_s1 = str_5;
	const char* str_s2 = str;
	int k = 0, cnt = 0;
	const int S = 256;
	int const la = strlen(str_5);
	int const lb = strlen(str);
	
	for (int i = 0; i < la; i++) {
		char tmp[S] = "";
		k = 0;
		if (str_5[i] == str[0]) {
			int j = i;
			while (str_5[j] == str[k]) {
				tmp[k] = str_5[j];
				j++; k++;
			}
			if (!(strcmp(str, tmp)))cnt++;
		}
	}
	return cnt;



}


int fun_kol_pred(char* str_5, char* str) {
	int ind = 0;
	for (int i = 0; i < strlen(str_5); i++) {
		if (str_5[i] == str[0]) {
			ind++;
		}
	}
	if (ind == 0) {
		ind = 1;
	}
	return ind;
}

void fun_perever(char* str_5) {

	int id = strlen(str_5)-1;
	int kol_slov=1;
	for (int i = 0; i < id; i++) {
			if (str_5[i] == ' ') {
				kol_slov++;
			}
		}
	int id_2 = 0;
	char t;
	while (id_2!=id/2) {
		t = str_5[id_2];
		str_5[id_2] = str_5[id - id_2];
		str_5[id - id_2] = t;
		id_2++;




	}
	int id_3 = -1;
	for (int i = 0; i < id; i++) {
		if (str_5[i] != ' ') {
			id_3++;
		}
		else {
			for (int j = id_3; j > id_3/2; j--) {
				t = str_5[i - j];
				str_5[i - j] = str_5[i - j + id_3];
				str_5[i - j + id_3] = t;
			}
			id_3 = -1;
		}

	}


}

void fun_pred_perever(char* str_5) {

}


int main() {
	int flag_menu = 0;
	char str[100] = { 0 };
	const char* str_1 = "15";
	char* str_2 = NULL;
	int number = 0;
	str_2 = " ";

	do {

		printf("\n Vvedite nomer functii 1-5 \n");
		scanf_s("%d", &flag_menu);
		fflush(stdin);

		if (flag_menu == 1) {
			printf("\n konvertaci9 stroki v 4islo :");
			printf("\n Vvedite stroky\n");
			while (getchar() != '\n');
			gets_s(str);
			number= string_to_number(str);
			printf("\nResultat= %d",number);
		}

		if (flag_menu == 2) {
			printf("\n konvertaci9  4islo v stroky :");
			printf("\n Vvedite 4islo = ");
			scanf_s("%d", &number);
			str_2 = number_to_string(str, number);
			printf("\n Resultat = %s,",str_2);
		}


		if (flag_menu == 3) {
			printf("\n konvertaci9 stroki v Verhnii registr :");
			printf("\n Vvedite stroky\n");
			while (getchar() != '\n');
			gets_s(str);
			upper_case(str);
			printf("\n Resultat = %s,", str);


		}

		if (flag_menu == 4) {
			printf("\n konvertaci9 stroki v nihnii registr :");
			printf("\n Vvedite stroky\n");
			while (getchar() != '\n');
			gets_s(str);
			lower_case(str);
			printf("\n Resultat = %s,", str);

		}


		if (flag_menu == 5) {

			char str_5[1000] = { 0 };

			printf("\n Vvedite text : \n");
			while (getchar() != '\n');
			gets_s(str_5);

			printf("\n Vvedite poiskovoe slovo = \n");
			while (getchar() != '\n');
			gets_s(str);
			number = fun_kol_slov(str_5, str);
			printf("\n Koli4estvo vhohdenii dannogo slova = %d",number);
			str[0] = '.';
			number = fun_kol_pred(str_5, str);
			printf("\n Koli4estvo predlohenii v tekste = %d",number);
			str[0] = '.';
			number = fun_kol_pred(str_5, str);
			printf("\n Koli4estvo to4ek v tekste = %d",number);
			str[0] = ',';
			number = fun_kol_pred(str_5, str);
			printf("\n Koli4estvo zap9tuh v tekste = %d", number);
			fun_perever(str_5);
			printf("\n Perevernuti text = \n %s",str_5);
			fun_pred_perever(str_5);
			printf("\n Perevernutie slova v predlohenu9h = \n %s", str_5);



		}




	} while (flag_menu != 0);
}
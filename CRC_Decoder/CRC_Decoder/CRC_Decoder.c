// CRC-8 Decoder
#include<stdio.h>
#include<string.h>

int main() {
	

	printf("CRC-8 디코더 (입력 24-bit, 출력 No error/ ERROR!!)\n");

	while (1)
	{
		char input_D[25] = { 0 };
	
		int input_D_modify_into_int[24] = { 0, };
	
		int Divisor_G[9] = { 1,0,0,0,0,0,1,1,1 };
	
		char Rimainder[9] = { 0 };
		printf("입력: ");

		scanf("%s", input_D);

		for (int i = 0; input_D[i]; i++) {
			//입력받은 문자열 input_D를 계산의 편의성을 위해 int형으로 변환하는 과정
			input_D_modify_into_int[i] = input_D[i] - '0';
		}

		for (int i = 0; i < 16; i++) {
				//맨 왼쪽부터 확인하여 비트가 1인 것을 확인하면 Divisor_G를 가지고 modulo 2 arithmetic 즉 xor연산을 후의 바뀐 division을 계속해서 갱신하는데
				//해당 과정을 Q의 비트의 최대의 개수 즉 몫이 나올수 있는 최대의 횟수 (k) 동안 반복하여 나머지를 구한다.

			if (input_D_modify_into_int[i] == 1) {
				for (int j = 0; j < 9; j++) {
					input_D_modify_into_int[i + j] = Divisor_G[j] ^ input_D_modify_into_int[i + j];
				}
			}

		}

		//몫이 나올수 있는 최대의 횟수 (k) 동안 반복하여 나온 division이 나머지가 된다.
		sprintf(Rimainder, "%d%d%d%d%d%d%d%d", input_D_modify_into_int[16], input_D_modify_into_int[17], input_D_modify_into_int[18], input_D_modify_into_int[19], input_D_modify_into_int[20], input_D_modify_into_int[21], input_D_modify_into_int[22], input_D_modify_into_int[23]);
		int result = strcmp(Rimainder, "00000000\0");
		if (result == 0) {
			printf("출력: NO ERROR!\n");
		}
		else {
			printf("출력: ERROR!!\n");
		}

	}
	return 0;
}
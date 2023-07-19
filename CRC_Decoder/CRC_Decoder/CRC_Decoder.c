// CRC-8 Decoder
#include<stdio.h>
#include<string.h>

int main() {
	

	printf("CRC-8 ���ڴ� (�Է� 24-bit, ��� No error/ ERROR!!)\n");

	while (1)
	{
		char input_D[25] = { 0 };
	
		int input_D_modify_into_int[24] = { 0, };
	
		int Divisor_G[9] = { 1,0,0,0,0,0,1,1,1 };
	
		char Rimainder[9] = { 0 };
		printf("�Է�: ");

		scanf("%s", input_D);

		for (int i = 0; input_D[i]; i++) {
			//�Է¹��� ���ڿ� input_D�� ����� ���Ǽ��� ���� int������ ��ȯ�ϴ� ����
			input_D_modify_into_int[i] = input_D[i] - '0';
		}

		for (int i = 0; i < 16; i++) {
				//�� ���ʺ��� Ȯ���Ͽ� ��Ʈ�� 1�� ���� Ȯ���ϸ� Divisor_G�� ������ modulo 2 arithmetic �� xor������ ���� �ٲ� division�� ����ؼ� �����ϴµ�
				//�ش� ������ Q�� ��Ʈ�� �ִ��� ���� �� ���� ���ü� �ִ� �ִ��� Ƚ�� (k) ���� �ݺ��Ͽ� �������� ���Ѵ�.

			if (input_D_modify_into_int[i] == 1) {
				for (int j = 0; j < 9; j++) {
					input_D_modify_into_int[i + j] = Divisor_G[j] ^ input_D_modify_into_int[i + j];
				}
			}

		}

		//���� ���ü� �ִ� �ִ��� Ƚ�� (k) ���� �ݺ��Ͽ� ���� division�� �������� �ȴ�.
		sprintf(Rimainder, "%d%d%d%d%d%d%d%d", input_D_modify_into_int[16], input_D_modify_into_int[17], input_D_modify_into_int[18], input_D_modify_into_int[19], input_D_modify_into_int[20], input_D_modify_into_int[21], input_D_modify_into_int[22], input_D_modify_into_int[23]);
		int result = strcmp(Rimainder, "00000000\0");
		if (result == 0) {
			printf("���: NO ERROR!\n");
		}
		else {
			printf("���: ERROR!!\n");
		}

	}
	return 0;
}
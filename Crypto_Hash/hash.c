#include "hash.h"

unsigned int Hash_K[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5 ,0x3956c25b ,0x59f111f1 ,0x923f82a4 ,0xab1c5ed5
,0xd807aa98 ,0x12835b01 ,0x243185be ,0x550c7dc3 ,0x72be5d74 ,0x80deb1fe ,0x9bdc06a7 ,0xc19bf174
,0xe49b69c1 ,0xefbe4786 ,0x0fc19dc6 ,0x240ca1cc ,0x2de92c6f ,0x4a7484aa ,0x5cb0a9dc ,0x76f988da
,0x983e5152 ,0xa831c66d ,0xb00327c8 ,0xbf597fc7 ,0xc6e00bf3 ,0xd5a79147 ,0x06ca6351 ,0x14292967
,0x27b70a85 ,0x2e1b2138 ,0x4d2c6dfc ,0x53380d13 ,0x650a7354 ,0x766a0abb ,0x81c2c92e ,0x92722c85
,0xa2bfe8a1 ,0xa81a664b ,0xc24b8b70 ,0xc76c51a3 ,0xd192e819 ,0xd6990624 ,0xf40e3585 ,0x106aa070
,0x19a4c116 ,0x1e376c08 ,0x2748774c ,0x34b0bcb5 ,0x391c0cb3 ,0x4ed8aa4a ,0x5b9cca4f ,0x682e6ff3
,0x748f82ee ,0x78a5636f ,0x84c87814 ,0x8cc70208 ,0x90befffa ,0xa4506ceb ,0xbef9a3f7 ,0xc67178f2
};

unsigned long long Hash_KK[80] = { 0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,	0x72be5d74f27b896f, 0x80deb1fe3b1696b1,	0x9bdc06a725c71235, 0xc19bf174cf692694,	0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,	0x2de92c6f592b0275, 0x4a7484aa6ea6e483,	0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,	0x983e5152ee66dfab, 0xa831c66d2db43210,	0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,	0x06ca6351e003826f, 0x142929670a0e6e70,	0x27b70a8546d22ffc, 0x2e1b21385c26c926,	0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,	0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b,	0xa2bfe8a14cf10364, 0xa81a664bbc423001,	0xc24b8b70d0f89791, 0xc76c51a30654be30,	0xd192e819d6ef5218, 0xd69906245565a910,	0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53,	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,	0x748f82ee5defb2fc, 0x78a5636f43172f60,
	0x84c87814a1f0ab72, 0x8cc702081a6439ec,	0x90befffa23631e28, 0xa4506cebde82bde9,	0xbef9a3f7b2c67915, 0xc67178f2e372532b,	0xca273eceea26619c, 0xd186b8c721c0c207,	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6,	0x113f9804bef90dae, 0x1b710b35131c471b,	0x28db77f523047d84, 0x32caab7b40c72493,	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };

unsigned int R_256(unsigned int x, unsigned int n) {
	return x >> n;
}

unsigned int S_256(unsigned int x, unsigned int n) {
	unsigned int temp = x;
	return (temp >> n) ^ (x << (32 - n));
}

unsigned int Ch_256(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ ((~x) & z);
}

unsigned int Maj_256(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ (x & z) ^ (y & z);
}

unsigned int Sum0_256(unsigned int x) {
	return S_256(x, 2) ^ S_256(x, 13) ^ S_256(x, 22);
}

unsigned int Sum1_256(unsigned int x) {
	return S_256(x, 6) ^ S_256(x, 11) ^ S_256(x, 25);
}

unsigned int Sigma0_256(unsigned int x) {
	return S_256(x, 7) ^ S_256(x, 18) ^ R_256(x, 3);
}

unsigned int Sigma1_256(unsigned int x) {
	return S_256(x, 17) ^ S_256(x, 19) ^ R_256(x, 10);
}

unsigned long long R_512(unsigned long long x, unsigned long long n) {
	return x >> n;
}

unsigned long long S_512(unsigned long long x, unsigned long long n) {
	unsigned long long temp = x;
	return (temp >> n) ^ (x << (32 - n));
}

unsigned long long Ch_512(unsigned long long x, unsigned long long y, unsigned long long z) {
	return (x & y) ^ ((~x) & z);
}

unsigned long long Maj_512(unsigned long long x, unsigned long long y, unsigned long long z) {
	return (x & y) ^ (x & z) ^ (y & z);
}

unsigned long long Sum0_512(unsigned long long x) {
	return S_512(x, 28) ^ S_512(x, 34) ^ S_512(x, 39);
}

unsigned long long Sum1_512(unsigned long long x) {
	return S_512(x, 14) ^ S_512(x, 18) ^ S_512(x, 41);
}

unsigned long long Sigma0_512(unsigned long long x) {
	return S_512(x, 1) ^ S_512(x, 8) ^ R_512(x, 7);
}

unsigned long long Sigma1_512(unsigned long long x) {
	return S_512(x, 19) ^ S_512(x, 61) ^ R_512(x, 6);
}

unsigned int Hash512() {
	unsigned long long fixed_H[8] = { 0x00, };
	unsigned long long H[8] = { 0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179 };
	unsigned long long M[16] = { 0x6162638000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
	 0x0000000000000000,  0x0000000000000000,  0x0000000000000000,  0x0000000000000000,  0x0000000000000000,  0x0000000000000000,  0x0000000000000000,  0x0000000000000018 };
	unsigned int M2[32] = { 0x61626364 ,0x62636465 ,0x63646566 ,0x64656667 ,0x65666768 ,0x66676869 ,0x6768696a ,0x68696a6b
,0x696a6b6c ,0x6a6b6c6d ,0x6b6c6d6e ,0x6c6d6e6f ,0x6d6e6f70 ,0x6e6f7071 ,0x80000000 ,0x00000000
,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000
,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x000001c0 };
	unsigned int N = 1;
	unsigned long long T1, T2;
	unsigned long long a, b, c, d, e, f, g, h;
	unsigned long long  W[80] = { 0x0000000000000000, };
	for (unsigned int i = 0; i < N; i++) {
		for (int m = 0; m < 8; m++)
			fixed_H[m] = H[m];
		for (int m = 0; m < 16; m++) {
			W[m] = M[m + (16 * i)];
		}
		for (int k = 16; k < 79; k++) {
			W[k] = Sigma1_512(W[k - 2]) + W[k - 7] + Sigma0_512(W[k - 15]) + W[k - 16];
		}
		a = H[0];
		b = H[1];
		c = H[2];
		d = H[3];
		e = H[4];
		f = H[5];
		g = H[6];
		h = H[7];
		for (int j = 0; j < 64; j++) {
			T1 = h + Sum1_512(e) + Ch_512(e, f, g) + Hash_KK[j] + W[j];
			T2 = Sum0_512(a) + Maj_512(a, b, c);
			h = g;
			g = f;
			f = e;
			e = d + T1;
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}
		H[0] = a + fixed_H[0];
		H[1] = b + fixed_H[1];
		H[2] = c + fixed_H[2];
		H[3] = d + fixed_H[3];
		H[4] = e + fixed_H[4];
		H[5] = f + fixed_H[5];
		H[6] = g + fixed_H[6];
		H[7] = h + fixed_H[7];
	}
	for (int t = 0; t < 8; t++)
		printf("%16x ", H[t]);
	printf("\n");

	return 0;
}

unsigned int Hash256() {
	unsigned int fixed_H[8] = { 0x00, };
	unsigned int H[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
	unsigned int M[16] = { 0x61626380, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018 };
	unsigned int M2[32] = { 0x61626364 ,0x62636465 ,0x63646566 ,0x64656667 ,0x65666768 ,0x66676869 ,0x6768696a ,0x68696a6b
,0x696a6b6c ,0x6a6b6c6d ,0x6b6c6d6e ,0x6c6d6e6f ,0x6d6e6f70 ,0x6e6f7071 ,0x80000000 ,0x00000000
,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000
,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x00000000 ,0x000001c0 };
	unsigned int N = 2;
	unsigned int T1, T2;
	unsigned int a, b, c, d, e, f, g, h;
	unsigned int W[64] = { 0x00000000, };
	for (unsigned int i = 0; i < N; i++) {
		for (int m = 0; m < 8; m++)
			fixed_H[m] = H[m];
		for (int m = 0; m < 16; m++) {
			W[m] = M2[m+(16*i)];
		}
		for (int k = 16; k < 64; k++) {
			W[k] = Sigma1_256(W[k - 2]) + W[k - 7] + Sigma0_256(W[k - 15]) + W[k - 16];
		}
		a = H[0];
		b = H[1];
		c = H[2];
		d = H[3];
		e = H[4];
		f = H[5];
		g = H[6];
		h = H[7];
		for (int j = 0; j < 64; j++) {
			T1 = h + Sum1_256(e) + Ch_256(e, f, g) + Hash_K[j] + W[j];
			T2 = Sum0_256(a) + Maj_256(a, b, c);
			h = g;
			g = f;
			f = e;
			e = d + T1;
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}
		H[0] = a + fixed_H[0];
		H[1] = b + fixed_H[1];
		H[2] = c + fixed_H[2];
		H[3] = d + fixed_H[3];
		H[4] = e + fixed_H[4];
		H[5] = f + fixed_H[5];
		H[6] = g + fixed_H[6];
		H[7] = h + fixed_H[7];
	}
	for (int t = 0; t < 8; t++)
		printf("%08x ", H[t]);
	printf("\n");

	return 0;
}
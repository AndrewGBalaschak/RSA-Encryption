#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <random>
#include <functional>

using namespace std;

int primes[1000] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919};

int encoded_ASCII[64] = {01100001,01100010,01100011,01100100,01100101,01100110,01100111,01101000,01101001,01101010,01101011,01101100,01101101,01101110,01101111,01110000,01110001,01110010,01110011,01110100,01110101,01110110,01110111,01111000,01111001,01111010,01000001,01000010,01000011,01000100,01000101,01000110,01000111,01001000,01001001,01001010,01001011,01001100,01001101,01001110,01001111,01010000,01010001,01010010,01010011,01010100,01010101,01010110,01010111,01011000,01011001,01011010,00110001,00110010,00110011,00110100,00110101,00110110,00110111,00111000,00111001,00110000,00111111,00100000};
char decoded_ASCII[64] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','?',' '};

class Key {
	public:
		unsigned long get_n(){
			return n;
		}
		unsigned long get_e(){
			return e;
		}
		unsigned long get_d(){
			return d;
		}
		void set_n(unsigned long n){
			this->n = n;
		}
		void set_e(unsigned long e){
			this->e = e;
		}
		void set_d(unsigned long d){
			this->d = d;
		}
	private:
		unsigned long n;
		unsigned long e;
		unsigned long d;
};

//modular exponentiation
unsigned long modpow(unsigned long base, unsigned long exp, unsigned long mod){
	unsigned long output = 1;
	while(exp > 0) {
		if(exp % 2 == 1)
			output = (output * base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}
	return output;
}

//implemented from Wikipedia pseudo-code and documentation
//returns true of candidate_prime is *probably* prime
bool miller_rabin_test(unsigned long candidate_prime, int passes){
	//for this section, candidate_prime is referrred to as n for berevity
	//let s > 0 and d odd > 0 such that n − 1 = 2^s * d
	//by factoring out powers of 2 from n − 1
	random_device rd;		//non-deterministic generator
	mt19937 gen(rd());		//to seed mersenne twister
	uniform_int_distribution<> dist(2, candidate_prime-2);

	unsigned long d = candidate_prime-1;
	unsigned long y = 0;
	while(d % 2 == 0)
		d /= 2;

	for(int i = 0; i < passes; i++){
		//a ← random(2, n − 2)
		//n is always a probable prime to base 1 and n − 1
		unsigned long a = dist(gen);

		//x ← a^d mod n
		unsigned long x = modpow(a, d, candidate_prime);

		while(d != (candidate_prime - 1)){
			//y ← x^2 mod n
			y = modpow(x, 2, candidate_prime);
			d *= 2;

			//if y = 1 and x ≠ 1 and x ≠ n − 1 then
			//nontrivial square root of 1 modulo n
			if(y == 1 && x != 1 && x != (candidate_prime - 1))
				return false;

			//x ← y
			x = y;			
		}
		if(y != 1)
			return false;
	}

	return true;
}

//generate x-bit prime number
unsigned long generate_random_prime(int bits){
	random_device rd;		//non-deterministic generator
	mt19937 gen(rd());		//to seed mersenne twister
	unsigned long max_bits = (unsigned long) pow(2, bits) - 1;		//largest number available for x bits
	unsigned long min_bits = (unsigned long) pow(2, bits-1) + 1;	//smallest number available for x bits
	uniform_int_distribution<> dist(min_bits, max_bits);

	bool not_prime = true;
	unsigned long candidate_prime = -1;

	//roll until we get a prime number
	while(not_prime){
		int i = 0;
		//generate a candidate prime within the bits
		candidate_prime = dist(gen);
		//cout << "Candidate: " << candidate_prime << endl;

		//If the candidate prime is divisible by any of the primes in our list
		//then it is not good enough for encryption and we re-roll,
		//this ensures that the number generated is coprime to the first 1000 primes
		//I am using this in place of a Fermat primality test since it seems it would be
		//more strict by guaranteeing that it only tests multiples of 2 one time
		for(i = 0; i < 1000; i++){
			if((candidate_prime % primes[i]) == 0){
				break;
			}
		}

		//check to see if we made it through all 1000 primes or if we terminated early
		if(i == 1000){
			//now we begin the more computationally expensive Miller-Rabin test to "guess"
			//whether a number is prime with a certain threshold for error

			if(miller_rabin_test(candidate_prime, 10))
				not_prime = false;
		}
	}
	return candidate_prime;
}

void sign_in(){
	string username, password;

	cout << "Enter user: ";
	cin >> username;
	cout << endl;

	cout << "Enter pass: ";
	cin >> password;
	cout << endl;

	hash<string> myHash;
}

unsigned long find_exponent(unsigned long phi, unsigned long n){
	random_device rd;		//non-deterministic generator
	mt19937 gen(rd());		//to seed mersenne twister
	uniform_int_distribution<> dist(3, phi);
	int exponent = dist(gen);

	//make sure random number is not a factor of n
	while(n % exponent == 0){
		exponent = dist(gen);
	}
	return exponent;
}

void generate_keys(Key* my_public_key, Key* my_private_key){
	unsigned long p = generate_random_prime(16);
	unsigned long q = generate_random_prime(16);
	unsigned long n = p * q;
	unsigned long phi = (p-1) * (q-1);
	unsigned long e = find_exponent(phi, n);
	unsigned long d = (2 * phi + 1) / e;

	cout << "P: " << p << endl;
	cout << "Q: " << q << endl;
	cout << "N: " << n << endl;
	cout << "E: " << e << endl;

	my_public_key->set_n(n);
	my_public_key->set_e(e);
	my_private_key->set_n(n);
	my_private_key->set_d(d);
}

int char_to_my_ASCII(char character){
	int index = -1;
	for(int i = 0; i < 64; i++){
		if(character == decoded_ASCII[i])
			index = i;
	}

	//if the character was not found, replace it with "?"
	if(index == -1)
		index = 62;

	return encoded_ASCII[index];
}

char my_ASCII_to_char(unsigned long data){
	int index = -1;
	for(int i = 0; i < 64; i++){
		if(data == encoded_ASCII[i]);
			index = i;
	}

	//if the character was not found, replace it with "?"
	if(index == -1)
		index = 62;

	return decoded_ASCII[index];
}

string encrypt(unsigned long data, Key key){
	//output = (data ^ e) % n
	//unsigned long output = (unsigned long) pow(data, key.get_e()) % key.get_n();
	unsigned long output = modpow(data, key.get_e(), key.get_n());
	return to_string(output);
}

string decrypt(unsigned long cypher, Key key){
	//output = (cypher ^ d) % n
	unsigned long output = modpow(cypher, key.get_d(), key.get_n());
	return to_string(output);
}

string encrypt_chunk(string data, Key key){
	string output = "";

	for(int i = 0; i < data.length(); i++){
		cout << data.at(i) << " : ";
		int encoded_ASCII = char_to_my_ASCII(data.at(i));
		cout << encoded_ASCII << " : ";

		string temp = encrypt(encoded_ASCII, key);
		cout << temp << endl;
		output.append(temp);
		output.append(",");
	}
	return output;
}

string decrypt_chunk(string data, Key key){
	string output;
	string temp = "";

	for(int i = 0; i < data.length(); i++){	
		if(data.at(i) != ','){
			temp += data.at(i);
		}
		else{
			output.append(decrypt(stoul(temp), key));
			output.append(",");
			temp = "";
		}
	}
	return output;
}

int main() {
	Key my_public_key;
	Key my_private_key;
	generate_keys(&my_public_key, &my_private_key);

	Key friend_public_key;

	string input;

	cout << "Type something: ";
	getline(cin, input);

	string encrypted_data = encrypt_chunk(input, my_public_key);
	cout << encrypted_data << endl;

	string decrypted_data = decrypt_chunk(encrypted_data, my_private_key);
	cout << decrypted_data << endl;

	return 0;
}
/*
 * @ brief Diffie-Hellman Algorithm ~ Cryptography;
        - Used to securely establish a shared secret key
        between two parties (Alice & Bob) over an insecure
        public channel.

 * @ author Angel S.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

void clear_screen();
void welcome();
void alice_private(int &a_key);
void bob_private(int &b_key);
void public_parameter(int &prime_p, int &gen_g);
void gen_exh(int &A_key, int &B_key);
int intro();


int main()
{
    int p, g, a, b, A, B;

    clear_screen();
    welcome();
    
    if (intro() == 1)
    {
        alice_private(a);
    }
    else if (intro() == 2)
    {
        bob_private(b);
    }

    public_parameter(p, g);

    gen_exh(A, B);

    return 0;
}

void clear_screen()
{
    std::cout << "\033[2J\033[H" << std::flush;
}

void welcome()
{
    std::ifstream welcome_file("welcome.txt");
    std::cout << std::endl << welcome_file.rdbuf() << std::endl;
}

// alice's private key
void alice_private(int &a_key)
{
    int a;
    std::cout << "\nOkay Alice, now choose a secret private integer a: ";
    std::cin >> a;
    std::cout << "\nAlice's private key: " << a << std::endl;
}

// bob's private key
void bob_private(int &b_key)
{
    int b;
    std::cout << "\nOkay Bob, now choose a secret private integer a: ";
    std::cin >> b;
    std::cout << "\nBob's private key: " << b << std::endl;
}

int intro()
{
    int alice_bob;

    std::cout << "Choose between (1) Alice or (2) Bob: " ;
    std::cin >> alice_bob;

    return alice_bob;
}


// alice's & bob's two public num
void public_parameter(int &prime_p, int &gen_g)
{
    int p, g;

    std::cout << "\nEnter the agreed upon prime number p and generator g: ";
    std::cin >> p >> g;

    std::cout << "\n|| Prime p: " << p << " || generator g: " << g <<  " ||" << std::endl;
}


// public key generation and exchange
// alice -> A = g^a mod p & sends A to Bob
// bob   -> B = g^b mod p & sends B to alice

void gen_exh(int &A_key, int &B_key)
{
    int p, g, A, B, a, b;
    public_parameter(p, g);
    alice_private(a);

    A = std::pow(g, a);

    std::cout << A << std::endl; 

}

// Shared secret calculation:
// Alice calculates s = B^a mod p
// Bob calculates s = A^b mod p


#include <iostream>
#include <algorithm>
#include <vector>
#include "windows.h"


//алфавіт
const int alphabet_size = 27;

char alphabet[alphabet_size] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '_'
 };

 // метод перетворення тексту в індекси
 void indexing(std::string text, std::vector<int> &index){
   for (size_t i = 0; i < text.size(); i++) {
    for (size_t j = 0; j < alphabet_size ; j++) {
    if (text[i]== alphabet[j]) {
      index.push_back(j);
    }
    }
   }
 }

// метод перетворення індексів в текст
 void texting( std::vector<int> index, std::string &text) {
   for (size_t i = 0; i < index.size(); i++) {
     for (size_t j = 0; j < alphabet_size; j++) {
       if (index[i]== j) {
         text+= alphabet[j];
       }
     }
   }
 }

 //метод, що шифрує текст на основі індексів масиву тесту та ключа
 void encrypt(std::vector<int> user_text_index, std::vector<int> key_index,
                             std::vector<int> &cipher_index ){
   for (size_t i = 0; i < user_text_index.size() ; i++) {
    if ((key_index[i]+user_text_index[i])>=alphabet_size) {
      cipher_index.push_back(key_index[i]+user_text_index[i]-alphabet_size);
    }
    else cipher_index.push_back(key_index[i]+user_text_index[i]);
   }
 }
  //метод, що дешефрує текст на основі індексу масиву тесту та ключа
 void decrypt(std::vector<int> user_text_index, std::vector<int> key_index,
                                          std::vector<int> &cipher_index){
     for (size_t i = 0; i < user_text_index.size() ; i++) {
      if ((user_text_index[i]-key_index[i])<0) {
        cipher_index.push_back(user_text_index[i]-key_index[i]+alphabet_size);
      }
      else cipher_index.push_back(user_text_index[i]-key_index[i]);
     }
  }

// метод, що приймає ключ та текст для шифрування/дешифрування та викликає відповідний метод
 std::string cipher(std::string word) {
  std::string user_key, user_text, key, cipher_text;
  std::vector<int> key_index, user_text_index, cipher_index, for_space;

  std::cout << "\nEnter key: ";
   std::cin >> user_key;
   std::transform(user_key.begin(), user_key.end(), user_key.begin(),
   [](unsigned char c){ return std::tolower(c); });

  std::cout << "\nEnter text: ";
    std:: cin.get();
   std:: getline(std::cin, user_text);
   std::transform(user_text.begin(), user_text.end(), user_text.begin(),
   [](unsigned char c){ return std::tolower(c); });

  while (key.size()<user_text.size()) {
    key+=user_key;
  }


 indexing(user_text, user_text_index);
 indexing(key, key_index);
 if (word== "encrypt") {
   encrypt(user_text_index, key_index, cipher_index);
    std::cout << "The encrypted text: \n\n"<< "\n\n";
 }
 else  if (word== "decrypt") {
   decrypt(user_text_index, key_index, cipher_index);
   std::cout << "The decrypted text: \n\n"<< "\n\n";
 }
      else {
        std::cerr << "Something went wrong..." << '\n';
    return "Error";
 }

   texting (cipher_index, cipher_text);
  return cipher_text;
 }

 int main() {

 std::string option;
 std::string choice;

  while (true) {
  std::cout << "\n\tChoose option: \n "<<
            "  Enter  '1' for Encrypt\n "<<
            "  Enter  '2' for Decrypt\n "<<
            "  Use '_' instead of ' ' " <<'\n';
        std::cout << "\nYour choice: ";
  // обираємо опцію та викликаємо метод з відповідним параметром або повідомлення про помилку
  std::cin >> option;
  if (option== "1") {
  std::cout << "Encrypt option:\n"<<cipher("encrypt")<< "\n\n";
  }
   else if (option== "2") {
    std::cout  << "Decrypt option:\n" <<  cipher("decrypt")<< "\n\n";
    }
  else std::cout << "Error, check data and try again" << '\n';

  Sleep(3000);
   answer:
  std::cout << "Do you wanna continue? [y/n]  "; std::cin >> choice;
     if (choice== "N" || choice== "n") {
std::cout << " I AM WAITING FOR YOUR COMMING BACK, BYE)))" << '\n';
     return 0;
     }
     else if (choice== "Y" || choice== "y") {
     }
     else {
       std::cout << " \n CHECK YOUR ANSWER. IT ISN`T CORRECT\n" << '\n';
       goto answer;
   }
  }
  return 0;
}

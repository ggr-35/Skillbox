#include <iostream>
#include <cstring>

bool substr(char* px,char* py){

 int k = 0;
 bool test = true;

    for (int i = 0; i <= (strlen(px) - strlen(py)); i++)
    {
        for (int j = i; k < strlen(py); j++)
        { 
        if(*(px + j) != *(py + k)){
            test = false;
            break;
        }
        ++k;
        } 

     if(test){
        return true;
     }

     test = true;
     k = 0;

    }
    return false;
}


int main() {

    
    char* a = "gewewraello graword!";
    char* b = "gera";
    char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c) << std::endl;
    
        
}




#include <iostream>
#include "Plataforma.hpp"
#include "Classificacio.hpp"
#include "BinaryTree.hpp"
#include "PriorityQueue.hpp"
#include "LlibreE.hpp"
using namespace std;

int main(){
    BinaryTree<string> topics;

    cin>>topics;
    Platform p = {topics};
    string input;
    cin >> input;
    while(input != "fi"){
        //INV: input channel instructions are executed.
        if(input == "alta_llibre"){
            cout<<input<<" "<<endl;
            Book b;
            cin >> b;
            p.registerBook(b.getTitle(), b.getPubDate(), b.getKeywords());
        }else if(input == "baixa_llibre"){
            cout<<input;
            string title;
            cin >> title;
            cout<<" "<<title<<endl;
            p.eliminateBook(title);
        }else if(input == "classifica_llibre"){
            cout<<input<<endl;
            p.classifyBook();

        }else if(input == "classifica"){
            cout<<input<<endl;
            p.classify();
        }else if(input == "mostra_llibres"){
            cout<<input<<" "<<endl;
            p.writeStorage();
        }else if(input == "llista_pendents"){
            cout<<input<<endl;
            p.pendingsList();
        }else if(input == "mostra_llibres_area"){
            cout<<input<<" ";
            string topic;
            cin >> topic;
            cout<<topic<<endl;
            p.showBooksTopic(topic);
        }else{
            cout << input <<endl;
            cout << "  error" << endl;
        }
        cin>>input;

    }
    cout << "fi" <<endl;
}

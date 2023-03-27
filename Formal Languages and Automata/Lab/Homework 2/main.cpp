#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");



int lungimeMax,stareFinala[100],nrStariFinale;
bool fout;

void afisare(char M[100][100][10],int nrStari)
{
    cout<<endl;
    for(int i=0;i<nrStari;i++)
    {
        for(int j=0;j<nrStari;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void afisDate(int nrStari,int nrMuchii,int stareInitiala, int nrStariFinale, int stareFinala[100],int lungimeMax)
{
    cout<<endl;
    cout<<"Numar de stari: "<<nrStari<<endl;
    cout<<"Numar de muchii: "<<nrMuchii<<endl;
    cout<<"Stare initiala: "<<stareInitiala<<endl;
    cout<<"Numar de stari finale: "<<nrStariFinale<<endl;
    cout<<"Stari finale: ";
    for(int i=0;i<nrStariFinale;i++)
        cout<<stareFinala[i]<<" ";
    cout<<endl;
    cout<<"Lungimea maxima admisa: "<<lungimeMax<<endl<<endl;
}

void cautare(char M[100][100][10],int nrStari,int lungimeActuala,int stareActuala,char cuv[100])
{
    for(int i=0;i<nrStariFinale;i++)
        if(stareActuala==stareFinala[i])
        {
            if(fout==false)
            {
                cout<<cuv<<endl;
                break;
            }

            else
            {
                out<<cuv<<endl;
                break;
            }
        }


    for(int j=0;j<nrStari;j++)
    {
        if(strcmp(M[stareActuala][j],"#")!=0 && lungimeActuala!=lungimeMax)
        {
            for(int i=0;i<strlen(M[stareActuala][j]);i++)
            {
                cuv[lungimeActuala]=M[stareActuala][j][i];
                for(int k=lungimeActuala+1;k<lungimeMax;k++)
                {
                   cuv[k]=' ';
                }
                cautare(M,nrStari,lungimeActuala+1,j,cuv);
            }
        }
    }
}


int main()
{
    int nrStari,stareInitiala,nrMuchii,st,dr,i,j;
    char M[100][100][10],val[100];
    bool fin,inMenu=true,inSubMenu=true;
    int choice;


    ///MENIU_________________________________________________________________________________
    while(inMenu==true)
    {
        cout<<"From where do you want to read data? 0->Console  1->File"<<endl;
        cin>>fin;

        cout<<"Where do you want to print data? 0->Console  1->File"<<endl;
        cin>>fout;

        ///citire nr stari------------------------------------------------------------------
        if(fin==false){
            cout<<"Nr stari: ";
            cin>>nrStari;
        }
        else{
            in>>nrStari;
        }



        for(i=0;i<nrStari;i++)
            for(j=0;j<nrStari;j++)
                strcpy(M[i][j],"#");


        ///citire nr muchii-------------------------------------------------------------------
        if(fin==false){
            cout<<"Nr muchii: ";
            cin>>nrMuchii;
        }
        else{
            in>>nrMuchii;
        }

        ///citire muchii+compl matrice adiacenta------------------------------------------------
        for(i=0;i<nrMuchii;i++)
        {

            if(fin==false)
                cin>>st>>dr>>val;
            else
                in>>st>>dr>>val;



            if(strcmp(M[st][dr],"#")==0)
                strcpy(M[st][dr],val);
            else
                strcat(M[st][dr],val);

        }


        ///citire stare initiala-------------------------------------------------------------------
        if(fin==false){
            cout<<"Stare initiala: ";
            cin>>stareInitiala;
        }
        else{
            in>>stareInitiala;
        }


        ///citire nr stare finala---------------------------------------------------------------------
        if(fin==false){
            cout<<"Nr stari finale: ";
            cin>>nrStariFinale;
        }
        else{
            in>>nrStariFinale;
        }


        ///citire stari finale-------------------------------------------------------------------------
        for(i=0;i<nrStariFinale;i++)
            if(fin==false){
                cout<<"Stari finale: ";
                cin>>stareFinala[i];
            }
            else{
                in>>stareFinala[i];
            }

            ///citire len max-------------------------------------------------------------------------
            if(fin==false){
                cout<<"Lungime maxima: ";
                cin>>lungimeMax;
            }
            else{
                in>>lungimeMax;
            }


        char cuv[lungimeMax+1];
        for(i=0;i<lungimeMax;i++)
            cuv[i]=' ';

        ///SUBMENIU_________________________________________________________________________________________
        inSubMenu=true;
        while(inSubMenu==true)
        {

            cout<<"Choose what to do..."<<endl;
            cout<<"1->Find all the accepted paths"<<endl;
            cout<<"2->Print the adjacency matrix"<<endl;
            cout<<"3->Print the data"<<endl;
            cout<<"Any other number->Leave"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                {
                    cautare(M,nrStari,0,stareInitiala,cuv);
                    break;
                }
            case 2:
                {
                    afisare(M,nrStari);
                    break;
                }
            case 3:
                {
                    afisDate(nrStari,nrMuchii,stareInitiala,nrStariFinale,stareFinala,lungimeMax);
                    break;
                }
            default:
                {
                    inSubMenu=false;
                    break;
                }
            }
        }

        cout<<"Do you want to run again?"<<endl;
        cout<<"0->No"<<endl;
        cout<<"1->Yes"<<endl;
        cin>>choice;

        if(choice==0)
            inMenu=false;
        }

    return 0;
}

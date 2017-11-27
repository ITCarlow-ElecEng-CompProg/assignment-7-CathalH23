/** Coordinate Conversion
 *  C00184521
 *  Cathal Hogan
 *  13/11/2017
 */

#include <iostream>
#include <math.h>

using namespace std;

// Functions
void Ctopolar ( float x, float y, float *ptr_rad, float *ptr_ang);
void PtoCartesian ( float rad, float ang, float *ptr_x, float *ptr_y);
char menu(void);
void pol2cart(void);
void cart2pol(void);

//main function
int main()
{   //Variable Declarations
    char userinput;

    cout << "Coordinate Conversion" << endl;

    do
    {
        userinput = menu();

        switch (userinput)
        {   // All calculations taking part in the functions
            case 'p':   cart2pol();
                        break;

            case 'c':   pol2cart();
                        break;
            //Quit the function
            case 'q':   cout <<"Goodbye, Have a lovely evening"<< endl;
                        break;
            // Prompy user to CHOOSE A LETTER AGAIN
            default:    cout << "Please choose correct program:"<<endl;
                        break;
        }
    }
    while (userinput != 'q');

    return 0;
}

void Ctopolar ( float x, float y, float *ptr_rad, float *ptr_ang)
{
    // Pointer value returned
    *ptr_rad = sqrt(pow(x,2)+ pow(y,2));
    *ptr_ang = 180.0 * (atan2(y,x))/M_PI;

    return;
}

void PtoCartesian ( float rad, float ang, float *ptr_x, float *ptr_y)
{   //Pointer value returned
    *ptr_x = rad * cos(ang);
    *ptr_y = rad * sin(ang);

    return;
}

//Select the operation required
char menu(void)
{
    //Variable declarationb
    char input;

    cout << "Choose conversion\n"<<
    "p = Cartesian to Polar coordinates\n"<<
    "c = Polar to Cartesian\n"<<
    "q = quit program.\n" << endl ;
    cin >> input;

    return input;
}

void cart2pol(void)
{
    //If p is choosen it will go this function
    float x =0, y=0, ang =0, rad =0;
    float *ptr_ang, *ptr_rad;

    ptr_ang = &ang;
    ptr_rad = &rad;

    cout << "Enter a valuie for x and y"<<endl;
    cin >> x >> y ;
    Ctopolar ( x, y, ptr_rad,ptr_ang);
    cout << "\nThe Magnitude of the angle is: " << *ptr_rad<< endl;
    cout << "The angle is:"<< *ptr_ang<< endl;

    return;
}

void pol2cart(void)
{   //If c is choosen it will got his function
    float x =0, y=0, ang =0, rad =0;
    float *ptr_x, *ptr_y;

    ptr_x = &x;
    ptr_y = &y;

    cout << "Enter the magnitude for R:"<<endl;
    cin >> rad;
    cout << "Enter the angle:"<<endl;
    cin >> ang;
    PtoCartesian (rad, ang*M_PI/180 ,ptr_x, ptr_y);
    cout <<"The x coOdinate is :"<< *ptr_x<< endl;
    cout << "The y coOrdinate is:" << *ptr_y << endl;

    return;
}

/*
Stefani Bekker
cssc4024
CS530 Spring 2019
Assignemt 1, Binary and Hex Dump
xbd
*/

# include "Header.h"

int main ( int argc, char *argv[] ){
// determining if the user wants the hex or binary dump and calling necessary function
    if(argc == 2){
        hexDump ( argv[1] );
    }
    if(argc == 3){
        binaryDump ( argv[2] );
    }
    return 0;
}

void hexDump ( char fileToDump[] ){
    /*
     hexdump function which reads in a file and outputs the text in the form of hex.
     It also writes out the address of the line, as well as the readble text.
     */
    long int addr = 0;
    unsigned char buffer[20];
    long int cnt;
    long int cnt2;
    ifstream file_in;
    long i;
    long n;
    int length = 0;
    file_in.open ( fileToDump );
    while (1){
        file_in.read ( ( char * ) buffer, 16 );
        cnt = file_in.gcount();
        if ( cnt <= 0 ){
            break;
        }
        //  Print the address
        cout << setfill('0') << setw(8) << addr << " ";
        addr += 16;
        cnt2 = 0;
        //  Print in Hex
        for ( n = 0; n < 16; n+=2 ){
                cnt2 += 1;
                if ( cnt2 <= cnt ){
                    cout << hex << setfill('0') << setw(2) << ( int ) buffer[n] << hex << setfill('0') << setw(2) << ( int ) buffer[n + 1];
                    length ++;
                }
                cout << " ";
        }
        
        cout << setfill ( ' ' );
        //testing if the hex text fills up the entire line space
        if(length < 8){
            for(int i = 0; i < 32 - (length*4); i ++){
                cout << " ";
            }
        }
        length = 0;
        cout << " ";
        cnt2 = 0;
        
        //  Print the printable characters, or a period if unprintable.
        
        for ( i = 0; i < n; i++ ){
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ){
                if ( buffer[i] < 32 || 126 < buffer[i] ){
                    cout << '.';
                }
                else{
                    cout << buffer[i];
                }
            }
        }
        cout << "\n";
        cout << dec;
        if ( file_in.eof ( ) ){
            break;
        }
    }
    file_in.close ( );
    return;
}

void binaryDump (char fileToDump[]){
    /*
     binary dump function which reads in a file and outputs the text in the form of binary.
     It also writes out the address of the line, as well as the readble text.
     */

    long int addr = 0;
    unsigned char buffer[20];
    long int cnt;
    long int cnt2;
    int remainder;
    ifstream file_in;
    long n;
    int length = 0;
    
    file_in.open ( fileToDump );
    
    while ( 1 ){
        file_in.read ( ( char * ) buffer, 6 );
        cnt = file_in.gcount();
        if ( cnt <= 0 ){
            break;
        }
        //  Print the address
        cout << setfill('0') << setw(8) << addr << " ";
        addr += 6;
        // Print in binary
        cnt2 = 0;
        for ( n = 0; n < 6; n++ ){
            int result = 0;
            int i = 1;
            int temp = buffer[n];
            cnt2 += 1;
            if ( cnt2 <= cnt ){
                while(temp != 0){
                    remainder = temp % 2;
                    result = result +(i * remainder);
                    temp = temp/2;
                    i *= 10;
                }
                cout << setw(8) << result;
                length++;
            }
            cout << " ";
        }
        cout << setfill ( ' ' );
        //testing if the binary text fills up the entire line space
        if(length < 6){
            for(int i = 0; i < 48 - (length*8); i ++){
                cout << " ";
            }
        }
        length = 0;
        cout << " ";
        cnt2 = 0;
        //  Print the printable characters, or a period if unprintable.
        for ( n = 0; n < 6; n++ ){
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ){
                if ( buffer[n] < 32 || 126 < buffer[n] ){
                    cout << '.';
                }
                else
                {
                    cout << buffer[n];
                }
            }
        }
        cout << "\n";
        cout << dec;
        if ( file_in.eof ( ) ){
            break;
        }
    }
    file_in.close ( );
    return;
}

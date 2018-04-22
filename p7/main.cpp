#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc, char* argv[])
{
  if(argc < 2)
    return 1;
  size_t n = atoi(argv[1]);
  char* megastring = NULL;
  char ministring[4];
  ministring[3] = ' ';
  for(size_t i = 0; i < n; i++)
    {
      ministring[0] = rand()%25+65;
      ministring[1] = rand()%25+65;
      ministring[2] = rand()%25+65;
      megastring = (char*)realloc(megastring, (i+1)*4);
      memcpy(megastring+i*4, ministring, 4);
    }
  //cout << megastring << endl;
  size_t count = 0;
  for(size_t i = 0; i < n*4; i++)
    {
      if(megastring [i++] == 'I')
        {
          if(megastring [i++] == 'P')
            {
              if(megastring [i++] == 'N')
                {
                  count++;
                }
            }
          else
            {
              i+=1;
            }
        }
      else
        {
          i+=2;
        }
    }
  cout << "found " << count << " 'IPN' ocurrences." << endl;
}


// C++ starter code for the shakespeare question. Compile and run it with:
//
// g++ -Wall -o decrypt decrypt.cpp && ./decrypt ../data/encrypted.txt ../data/plain.txt
//
// If you want to use C++11, use the Vagrant linux instance.
// $ vagrant up
// $ vagrant ssh
// $ cd /mnt/shakespeare/cpp
//
// Changes to the file on the host machine are automatically synced to the Vagrant instance
// Compile and run the code with:
//
// g++ -std=c++0x -Wall -o decrypt decrypt.cpp && ./decrypt ../data/encrypted.txt ../data/plain.txt
//

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <map>
using namespace std;

static int readFile(const char *path, std::string *pResult);

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

void readEncText (string fname)
{
		map<char, int> mapChars;
		//int arrPlain [26];

	  string line;
	  ifstream myfile (fname);
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      //cout << line << '\n';
	      for (int i = 0; i < line.length(); ++i)
	      {
	    	  char ch = toupper (line[i]);
	    	  //cout << "--------------" << line [i] << "=" << ch << endl;

			  if ((ch > 'A' && ch < 'Z'))
	    	  {
			  	  int index = ch - 'A';

	    		  map<char, int>::iterator it = mapChars.find (ch);
	    		  if (it != mapChars.end())
	    		  {
	    			  ++it->second;
	    		  }
	    		  else
	    			  mapChars [ch] = 1;
	    	  }
	      }
	    }
	    myfile.close();
	  }

	  // print out the map
	 /* map<char, int>::iterator it = mapChars.begin();
	  for (; it != mapChars.end(); ++it)
	  {
		  cout << it->first << "=" << it->second << endl;
	  }*/

	  std::multimap<int, char> dst = flip_map(mapChars);
	  cout << "After sorting Encypted file on value ----------- \n";
	  map<int, char>::iterator itflip = dst.begin();
	  for (; itflip != dst.end(); ++itflip)
	  {
	    cout << itflip->first << "=" << itflip->second << endl;
	  }


}

void readPlainText (string fname)
{
		map<char, int> mapChars;
		//int arrPlain [26];

	  string line;
	  ifstream myfile ("/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/plain.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      //cout << line << '\n';
	      for (int i = 0; i < line.length(); ++i)
	      {
	    	  char ch = toupper (line[i]);
	    	  //cout << "--------------" << line [i] << "=" << ch << endl;

			  if ((ch > 'A' && ch < 'Z'))
	    	  {
			  	  int index = ch - 'A';

	    		  map<char, int>::iterator it = mapChars.find (ch);
	    		  if (it != mapChars.end())
	    		  {
	    			  ++it->second;
	    		  }
	    		  else
	    			  mapChars [ch] = 1;
	    	  }
	      }
	    }
	    myfile.close();
	  }

	  // print out the map
	  map<char, int>::iterator it = mapChars.begin();
	  for (; it != mapChars.end(); ++it)
	  {
		  cout << it->first << "=" << it->second << endl;
	  }

	  std::multimap<int, char> dst = flip_map(mapChars);
	  cout << "After sorting on value ----------- \n";
	  map<int, char>::iterator itflip = dst.begin();
	  for (; itflip != dst.end(); ++itflip)
	  {
	    cout << itflip->first << "=" << itflip->second << endl;
	  }


}

int main(int argc, const char** argv) {
  std::string encryptedText, plainText;

  /* if (readFile("/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/encrypted.txt", &encryptedText) != 0) {
    std::cerr << "Error reading file: " << argv[1] << std::endl;
    return 1;
  }
  if (readFile("/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/plain.txt", &plainText) != 0) {
    std::cerr << "Error reading file: " << argv[2] << std::endl;
    return 1;
  }

  std::cout << "The size of " << "/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/encrypted.txt" << " is " << encryptedText.size() << " bytes." << std::endl;
  std::cout << "The size of " << "/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/plain.txt" << " is " << plainText.size() << " bytes." << std::endl;
	*/

  // TODO: your code goes here

  readPlainText ("/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/plain.txt");
  readEncText ("/Users/rudolpharaujo/desktop/mobile app/shakespeare/data/encrypted.txt");




  return 0;
}

int readFile(const char *path, std::string *pResult) {
  std::ifstream file(path);
  if (file.is_open()) {
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    *pResult = str;
    return 0;
  } else {
    return 1;
  }
}

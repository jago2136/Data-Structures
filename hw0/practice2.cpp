// Chapter 6, Streama and File I/O
#include <iostream>
#include <fstream> //Used if you want to use stream variables
using namespace std;

//Input delivered to a program is a stream: a flow of data
//Input and output streams (cin and cout)
//Work with files because files are permenant
//When taking in data its reading, when sending output to a file its writing
//If you want to change something already ran through, you can't "backup", you have to start over
//Stream is a special kind of variable, an object


int main ()
{
	//ifstream used for declaration instream variables
	//ofstream used for declaration outstream variables
	//in_stream.open("infilename.txt") used to open a file                  //ifsream and ofstream both are classes, with a member called "close"
	//out_stream.open("outfilename.txt")

	ifstream in_stream;                     // a file has two names
	ofstream out_stream;                    // after opening the file with("outfilename.txt"), now refer to is as the stream name out_stream
	int x, y, z;

	// for instream data
	//in_stream >> x >> y;
	//for outstreams
	//out_stream << "the numbers =" << x << y;

	//every file should be closed with either in_stream.close(); or out_stream.close()


	return 0;
}


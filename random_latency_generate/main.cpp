#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

#include "random_seq_output.h"

#include "histogram_input.h"

string random_output_file = "random_seq_output.h";
#define RANDOM_FACTOR 10

int main()
{
   size_t random_seq_size = 0;

   std::vector<int> seq;
   std::vector<int> random_seq;
   std::map<int, int> real_histogram;

   int i;

   for ( i = 0 ; i < latency_profile.size(); i++ )
   {
      //printf("i:%d, second:%d, random_seq_size:%d\n", i, latency_profile[i].second, random_seq_size);
      real_histogram[latency_profile[i].first] = 0;
      while (latency_profile[i].second--)
      {
          seq.push_back(latency_profile[i].first);
          random_seq_size++;
      }
   }

   printf("input histogram size:%lu\n output histogram size:%lu\n", random_seq_size, random_seq_size * RANDOM_FACTOR );

   /* initialize random seed: */
   srand (time(NULL));

   unsigned long total_value = 0;
   for ( i = 0 ; i < random_seq_size * RANDOM_FACTOR; i++ )
   {
      int value = rand() % random_seq_size;
      random_seq.push_back(seq[value]);
      /*calculate back the real histogram */
      real_histogram[seq[value]]++;
      total_value += seq[value];
   }

   printf("average value:%d\n", (unsigned int) (total_value/random_seq_size / RANDOM_FACTOR));

   for (auto &it:real_histogram)
   {
     printf(" real histogram: value:%d, count :%d\n", it.first, it.second);
   }


  ofstream outputfile;
  outputfile.open(random_output_file);

  /* write the real histogram */
  outputfile << "static int histogram[][2] = {\n";
  for (auto &it:real_histogram)
  {
    outputfile << "{" << it.first << " , " << it.second << "}" << ",\n";
  }
  outputfile << "};\n";

  /* write the random sequence to file */
  outputfile << "static short random_seq[" << random_seq.size() << "] = {\n";

  for (i = 0; i < random_seq.size(); i++ )
  {
    outputfile << random_seq[i] << ",";
  }

  outputfile << "};\n";

  outputfile.close();

 cout << "the output file is:" << random_output_file << endl;


return 0;
}

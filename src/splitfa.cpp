#include <string>
#include "SeqReader.h"
#include "Util.h"

static int kmer_len = 50;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "splitfa <in.fa> [len=%d]\n", kmer_len);
    return 1;
  }

  std::string fasta_file(argv[1]);

  if (argc >= 3) kmer_len = std::atoi(argv[2]);
  fprintf(stderr, "[splitfa] using len=%d\n", kmer_len);

  SeqReader reader(fasta_file, SRF_NO_VALIDATION);
  SeqRecord record;

  while (reader.get(record)) {
    std::string seq = record.seq.toString();
    int l = seq.length();
    if (l < kmer_len) continue;    
    for (int i = 0; i <= l - kmer_len; i++) {
      printf(">%s_%d\n", record.id.c_str(), i+1);
      for (int j = 0; j < kmer_len; ++j)
	putchar(seq[i + j]);
      putchar('\n');
    }
  }
  return 0;
}

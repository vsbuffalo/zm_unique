# Homebrewed Uniqueness Track based on bwa-mem

## Information Gathered

Following ENCODE's precedent, this method generates:

 - alignability: `1/n` where *n* is the number of positions that a
   sequence maps to across the genome.

 - uniqueness: unique regions in the genome; however our measure is
   calculated through mapping rather than with k-mers. Uniquness is
   `1/m` where *m* is the number of secondary alignments with the
   *same* alignment score.

 - mapping quality: the raw mapping quality of the read.

 - alignment score - secondary alignment score: this provides more
   information about the quality of the secondary alignments than just
   alignability and uniquness. This is primarily used for assessment.

## BWA command

    splitref 100 ref.fa | bwa mem -t 60 -c 1000000000 -M ref.fa | cov_track > cov_stats.bed


## Resources on Mapability

 - http://davetang.org/muse/2013/07/08/encode-mappability/

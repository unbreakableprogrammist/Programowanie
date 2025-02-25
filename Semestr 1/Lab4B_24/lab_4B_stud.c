#include <stdio.h>
#include <stdlib.h>

#define FINISH_LINE 20
#define MAX_STEPS 4

// ETAP 1 - definicje struktur:

//void sort(race* T);

// ETAP 2
//int init_reindeer(/* uzupelnij parametry*/);
//void print_reindeer(/* uzupelnij parametry*/);

// ETAP 3
//void add_to_ranking(/* uzupelnij parametry*/);
//int remove_reindeer(/* uzupelnij parametry*/);
//void move_reindeer(/* uzupelnij parametry*/);

// ETAP 4
//void simulate(/* uzupelnij parametry*/);

int main() {
  srand(42);
  int N = 8;
  int result;

  // ETAP 2 (2 pkt)
  /*
  printf("======= ETAP 2 =======\n");
  race reindeerRace;
  result = init_reindeer(&reindeerRace, N);
  if (result != 0) {
    printf("Error!\n");
  }
  print_reindeer(reindeerRace);

  race temporaryRace;
  result = init_reindeer(&temporaryRace, 2);
  if (result != 0) {
    printf("Error!\n");
  }
  print_reindeer(temporaryRace);
  free(temporaryRace.reindeers);
  */

  // ETAP 3 (2 pkt)
  /*
  printf("\n======= ETAP 3 =======\n");
  ranking reindeerRanking = { -1, -1, -1, 0 };
  add_to_ranking(&reindeerRanking, 3, reindeerRace);
  add_to_ranking(&reindeerRanking, 5, reindeerRace);
  add_to_ranking(&reindeerRanking, 2, reindeerRace);
  add_to_ranking(&reindeerRanking, 1, reindeerRace);
  add_to_ranking(&reindeerRanking, 6, reindeerRace);

  printf("Pierwsze miejsce: %d\n", reindeerRanking.firstPlace);
  printf("Drugie miejsce: %d\n", reindeerRanking.secondPlace);
  printf("Trzecie miejsce: %d\n", reindeerRanking.thirdPlace);
  printf("Pozostale renifery w rankingu: %d\n\n", reindeerRanking.others);

  print_reindeer(reindeerRace);
  printf("\nUsuwam renifera o indeksie 3\n\n");
  result = remove_reindeer(&reindeerRace, 3);
  if (result != 0) {
    printf("Error!\n");
  }

  print_reindeer(reindeerRace);
  printf("\nUsuwam renifera o indeksie 6\n\n");
  result = remove_reindeer(&reindeerRace, 6);
  if (result != 0) {
    printf("Error!\n");
  }
  print_reindeer(reindeerRace);

  printf("\nRuch reniferow:\n");
  move_reindeer(&reindeerRace, 3, 5);
  move_reindeer(&reindeerRace, 2, 3);
  move_reindeer(&reindeerRace, 5, 2);
  print_reindeer(reindeerRace);
  */

  // ETAP 4 (2 pkt)
  /*
  printf("\n======= ETAP 4 =======\n");
  race finalreindeerRace;
  ranking finalRindeerRanking = { -1, -1, -1, 0 };
  init_reindeer(&finalreindeerRace, 7);

  simulate(&finalreindeerRace, &finalRindeerRanking);
  
  printf("Pierwsze miejsce: %d\n", finalRindeerRanking.firstPlace);
  printf("Drugie miejsce: %d\n", finalRindeerRanking.secondPlace);
  printf("Trzecie miejsce: %d\n", finalRindeerRanking.thirdPlace);
  printf("Pozostale renifery w rankingu: %d\n", finalRindeerRanking.others);

  free(reindeerRace.reindeers);
  free(finalreindeerRace.reindeers);
  */
  return 0;
}

/*
void sort(race* T) {
  size_t n = T->size;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (T->reindeers[j].position < T->reindeers[j + 1].position) {
        reindeer temp = T->reindeers[j];
        T->reindeers[j] = T->reindeers[j + 1];
        T->reindeers[j + 1] = temp;
      }
    }
  }
}
*/

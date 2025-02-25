#include <stdio.h>
#include <stdlib.h>

#define FINISH_LINE 20
#define MAX_STEPS 4

// ETAP 1 - definicje struktur:

typedef struct reindeer {
    int id;
    int position;
} reindeer;

typedef struct race {
    reindeer* reindeers;
    int size;
} race;

typedef struct ranking {
    int firstPlace;
    int secondPlace;
    int thirdPlace;
    int others;
} ranking;

void sort(race* T);

// ETAP 2
int init_reindeer(race* T, int n);
void print_reindeer(race T);

// ETAP 3
void add_to_ranking(ranking* R, int i, race T);
int remove_reindeer(race* T, int i);
void move_reindeer(race* T, int i, int steps);

// ETAP 4
void simulate(race* T, ranking* R);

int main() {
    srand(42);
    int N = 8;
    int result;

    // ETAP 2 (2 pkt)
    
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
    
    // ETAP 3 (2 pkt)
    
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
    

    // ETAP 4 (2 pkt)
    
    printf("\n======= ETAP 4 =======\n");
    race finalreindeerRace;
    ranking finalRindeerRanking = { -1, -1, -1, 0 };
    init_reindeer(&finalreindeerRace, 7);

    simulate(&finalreindeerRace, &finalRindeerRanking);

    printf("\nPierwsze miejsce: %d\n", finalRindeerRanking.firstPlace);
    printf("Drugie miejsce: %d\n", finalRindeerRanking.secondPlace);
    printf("Trzecie miejsce: %d\n", finalRindeerRanking.thirdPlace);
    printf("Pozostale renifery w rankingu: %d\n", finalRindeerRanking.others);

    free(reindeerRace.reindeers);
    free(finalreindeerRace.reindeers);
    
    return 0;
}


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

int init_reindeer(race* T, int n) {
    int i;
    static int r_id = 0;

    reindeer r;
    r.position = 0;

    T->reindeers = (reindeer*)malloc(n * sizeof(reindeer));

    if (T == NULL) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        r.id = r_id;
        r_id++;
        
        T->reindeers[i] = r;
    }

    T->size = n;

    return 0;

}

void print_reindeer(race T) {
    int i;

    for (i = 0; i < T.size; i++) {
        printf("Renifer %d: pozycja %d\n", T.reindeers[i].id, T.reindeers[i].position);
    }

    return;
}

void add_to_ranking(ranking* R, int i, race T) {
    if (R->firstPlace == -1) {
        R->firstPlace = T.reindeers[i].id;
    }
    else if (R->secondPlace == -1) {
        R->secondPlace = T.reindeers[i].id;
    }
    else if (R->thirdPlace == -1) {
        R->thirdPlace = T.reindeers[i].id;
    }
    else {
        R->others++;
    }

    return;
}

int remove_reindeer(race* T, int i) {
    /*int j;

    for (j = 0; j < T->size; j++) {
        if (T->reindeers[j].id == i) {
            break;
        }
    }*/

    if (T->size - 1 == 0) {
        T->reindeers = NULL;
        T->size = 0;
        return 0;
    }

    for (; i < T->size - 1; i++) {
        T->reindeers[i] = T->reindeers[i + 1];
    }

    T->reindeers = (reindeer*)realloc(T->reindeers, (T->size-1) * sizeof(reindeer));
    
    if (T->reindeers == NULL) {
        return -1;
    }

    T->size--;

    return 0;
}

void move_reindeer(race* T, int i, int steps) {
    T->reindeers[i].position += steps;

    sort(T);

    return;
}

void simulate(race* T, ranking* R) {
    int i, t = 0;

    while (T->size > 0) {
        printf("\nt=%d\n", t);
        print_reindeer(*T);
        t++;

        // losujemy pozycje w rundzie
        for (i = 0; i < T->size; i++) {
            move_reindeer(T, i, 1 + rand() % (MAX_STEPS));
        }

        // wstawiamy renifery z pozycja >= 20 do rankingu i usuwamy z T
        for (i = 0; i < T->size; i++) {
            if (T->reindeers[i].position >= FINISH_LINE) {
                add_to_ranking(R, i, *T);
                remove_reindeer(T, i);
                i--;
            }
            else if (T->reindeers[i].position < FINISH_LINE) {
                break;
            }
        }
    }

    return;
}



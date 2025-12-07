/*
 * German Verb Master (A1 Level)
 * A complete quiz covering Regular, Irregular, and Separable verbs.
 *
 * NEW CONCEPTS USED:
 * 1. Structs: A way to group data (like a question, options, and answer) together.
 * 2. Arrays: Lists of those structs.
 * 3. Loops: To go through the list automatically.
 * 4. Randomization: We shuffle the questions so they are in a different order every time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Needed for random numbers

// --- 1. Define the "Question" Structure ---
// Instead of writing variables for every single question, we define a blueprint.
typedef struct {
    char verb[50];      // The verb to translate (e.g., "machen")
    char opt1[30];      // Option 1
    char opt2[30];      // Option 2
    char opt3[30];      // Option 3
    int correct;        // The number of the correct option (1, 2, or 3)
} Question;

// --- 2. The Data Lists ---

// LIST 1: REGULAR VERBS (Schwache Verben) - Standard "ge- -t" or "-iert"
Question regularVerbs[] = {
    {"machen (to do)", "gemachen", "gemacht", "gemocht", 2},
    {"lernen (to learn)", "gelernt", "gelernen", "gelehrnt", 1},
    {"kaufen (to buy)", "gekaufen", "gekauft", "gekäuft", 2},
    {"wohnen (to live)", "gewohnt", "gewohnen", "gewöhnt", 1},
    {"sagen (to say)", "gesagt", "gesagen", "sagt", 1},
    {"fragen (to ask)", "gefragt", "gefragen", "frug", 1},
    {"hören (to hear)", "gehoren", "gehört", "gehören", 2},
    {"suchen (to search)", "gesucht", "gesuchen", "gesehen", 1},
    {"brauchen (to need)", "gebrauchen", "gebraucht", "gebräucht", 2},
    {"spielen (to play)", "gespielen", "gespielt", "gespült", 2},
    {"arbeiten (to work)", "gearbeitet", "gearben", "gearbeite", 1},
    {"antworten (to answer)", "geantwortet", "geantwort", "geantworte", 1},
    {"glauben (to believe)", "geglaubt", "geglauben", "gegläubt", 1},
    {"leben (to live/exist)", "geleben", "gelebt", "geliebt", 2},
    {"lieben (to love)", "geliebt", "gelieben", "gelebt", 1},
    {"lachen (to laugh)", "gelacht", "gelachen", "gelächt", 1},
    {"weinen (to cry)", "geweint", "geweinen", "gewonnen", 1},
    {"kochen (to cook)", "gekocht", "gekochen", "gekücht", 1},
    {"warten (to wait)", "gewartet", "gewarten", "gewahrt", 1},
    {"baden (to bathe)", "gebadet", "gebaden", "gebad", 1},
    {"duschen (to shower)", "geduscht", "geduschen", "geduschen", 1},
    {"frühstücken (to eat breakfast)", "gefrühstückt", "gefrühstücken", "gefrühstuck", 1},
    {"putzen (to clean)", "geputzt", "geputzen", "gepatzt", 1},
    {"tanzen (to dance)", "getanzt", "getanzen", "getänzt", 1},
    {"reisen (to travel)", "gereist", "gereisen", "gerissen", 1},
    {"wandern (to hike)", "gewandert", "gewandern", "gewandet", 1},
    {"kosten (to cost)", "gekostet", "gekosten", "geküstet", 1},
    {"schmecken (to taste)", "geschmeckt", "geschmecken", "geschmuckt", 1},
    {"holen (to fetch)", "geholt", "geholen", "gehält", 1},
    {"feiern (to celebrate)", "gefeiert", "gefeieren", "gefeuert", 1},
    {"schenken (to gift)", "geschenkt", "geschenken", "geschankt", 1},
    {"schicken (to send)", "geschickt", "geschicken", "gescheckt", 1},
    {"wünschen (to wish)", "gewünscht", "gewünschen", "gewunscht", 1},
    {"üben (to practice)", "geübt", "geüben", "geoubt", 1},
    {"zeigen (to show)", "gezeigt", "gezeigen", "gezogen", 1},
    {"öffnen (to open)", "geöffnet", "geoffnet", "geoffnen", 1},
    {"zahlen (to pay)", "gezahlt", "gezahlen", "gezählt", 1},
    {"zählen (to count)", "gezählt", "gezählen", "gezahlt", 1},
    {"malen (to paint)", "gemalt", "gemalen", "gemahlt", 1},
    {"reden (to talk)", "geredet", "gereden", "geraten", 1},
    {"hoffen (to hope)", "gehofft", "gehoffen", "gehauft", 1},
    {"danken (to thank)", "gedankt", "gedanken", "gedünkt", 1},
    {"fehlen (to be missing)", "gefehlt", "gefehlen", "gefahlen", 1},
    {"passen (to fit)", "gepasst", "gepassen", "passiert", 1},
    {"stimmen (to be correct)", "gestimmt", "gestimmen", "gestummen", 1},
    {"klettern (to climb)", "geklettert", "geklettern", "geklommen", 1},
    {"bluten (to bleed)", "geblutet", "gebluten", "geblatt", 1},
    {"husten (to cough)", "gehustet", "gehusten", "gehastet", 1},
    {"buchstabieren (to spell)", "gebuchstabiert", "buchstabiert", "gebuchstuben", 2}, // -ier verbs no ge-
    {"studieren (to study)", "gestudiert", "studiert", "gestudieren", 2},
    {"fotografieren (to photograph)", "gefotografiert", "fotografiert", "fotografieren", 2},
    {"telefonieren (to call)", "getelefoniert", "telefoniert", "telephonen", 2},
    {"reparieren (to repair)", "gerepariert", "repariert", "reparieren", 2},
    {"funktionieren (to work/function)", "gefunktioniert", "funktioniert", "gefunktionieren", 2},
    {"diskutieren (to discuss)", "gediskutiert", "diskutiert", "diskutieren", 2},
    {"informieren (to inform)", "geinformiert", "informiert", "informieren", 2},
    {"kontrollieren (to control)", "gekontrolliert", "kontrolliert", "kontrollieren", 2},
    {"gratulieren (to congratulate)", "gegratuliert", "gratuliert", "gratulieren", 2},
    {"passieren (to happen)", "gepassiert", "passiert", "passieren", 2},
    {"reservieren (to reserve)", "gereserviert", "reserviert", "reservieren", 2},
    {"probieren (to try)", "geprobiert", "probiert", "probieren", 2},
    {"rasieren (to shave)", "gerasiert", "rasiert", "rasieren", 2},
    {"interessieren (to interest)", "geinteressiert", "interessiert", "interessieren", 2},
    {"besuchen (to visit)", "gebesucht", "besucht", "besuchen", 2}, // be- prefix
    {"bestellen (to order)", "gebestellt", "bestellt", "bestellen", 2},
    {"bezahlen (to pay)", "gebezahlt", "bezahlt", "bezahlen", 2},
    {"erzählen (to tell story)", "geerzählt", "erzählt", "erzahlen", 2},
    {"erklären (to explain)", "geerklärt", "erklärt", "erklarren", 2},
    {"verkaufen (to sell)", "geverkauft", "verkauft", "verkaufen", 2},
    {"versuchen (to try)", "geversucht", "versucht", "versuchen", 2},
    {"verdienen (to earn)", "geverdient", "verdient", "verdienen", 2},
    {"übernachten (to stay over)", "geübernachtet", "übernachtet", "übernächtigen", 2},
    {"wiederholen (to repeat)", "gewiederholt", "wiederholt", "wiederholen", 2},
    {"entschuldigen (to excuse)", "geentschuldigt", "entschuldigt", "entschulden", 2},
    {"bedeuten (to mean)", "gebedeutet", "bedeutet", "bedeuten", 2},
    {"gehören (to belong)", "gegehört", "gehört", "gehören", 2},
    {"benutzen (to use)", "gebenutzt", "benutzt", "benutzen", 2},
    {"übersetzen (to translate)", "geübersetzt", "übersetzt", "übersetzen", 2},
    {"vermieten (to rent out)", "gevermietet", "vermietet", "vermieten", 2},
    {"erreichen (to reach)", "geerreicht", "erreicht", "erreichen", 2}
};

// LIST 2: IRREGULAR VERBS (Starke Verben) - Vowel changes, -en ending
Question irregularVerbs[] = {
    {"sein (to be)", "gesein", "gewesen", "gewart", 2},
    {"haben (to have)", "gehaben", "gehat", "gehabt", 3},
    {"werden (to become)", "gewerden", "geworden", "gewurden", 2},
    {"gehen (to go)", "gegangen", "gegehen", "ging", 1},
    {"fahren (to drive)", "gefahren", "gefuhren", "gefahr", 1},
    {"kommen (to come)", "gekommen", "gekam", "gekommst", 1},
    {"essen (to eat)", "geessen", "gegessen", "gessen", 2},
    {"trinken (to drink)", "getrunken", "getrinken", "getrank", 1},
    {"schlafen (to sleep)", "geschlafen", "geschliefen", "geschlaft", 1},
    {"sehen (to see)", "gesehen", "gesieht", "gesah", 1},
    {"lesen (to read)", "gelesen", "gelest", "gelas", 1},
    {"sprechen (to speak)", "gesprochen", "gesprechen", "gesprachen", 1},
    {"schreiben (to write)", "geschrieben", "geschreibt", "geschreiben", 1},
    {"treffen (to meet)", "getroffen", "getreffen", "getrafen", 1},
    {"nehmen (to take)", "genehmen", "genommen", "genahmen", 2},
    {"geben (to give)", "gegeben", "gegabt", "gegibt", 1},
    {"helfen (to help)", "geholfen", "gehelfen", "gehulfen", 1},
    {"finden (to find)", "gefunden", "gefinden", "gefandet", 1},
    {"singen (to sing)", "gesingen", "gesungen", "gesangt", 2},
    {"schwimmen (to swim)", "geschwummen", "geschwommen", "geschwimmen", 2},
    {"bleiben (to stay)", "gebleiben", "geblieben", "gebleibt", 2},
    {"stehen (to stand)", "gestanden", "gestehen", "gestehn", 1},
    {"verstehen (to understand)", "verstanden", "versteht", "verstunden", 1},
    {"tun (to do)", "getun", "getan", "getaten", 2},
    {"bringen (to bring)", "gebringen", "gebracht", "gebrangt", 2}, // Mixed
    {"denken (to think)", "gedenkt", "gedacht", "gedanken", 2}, // Mixed
    {"kennen (to know people)", "gekennt", "gekannt", "gekonnt", 2}, // Mixed
    {"wissen (to know facts)", "gewissen", "gewusst", "geweiss", 2}, // Mixed
    {"nennen (to name)", "genennt", "genannt", "genunnt", 2}, // Mixed
    {"rennen (to run)", "gerennt", "gerannt", "gerunnen", 2}, // Mixed
    {"brennen (to burn)", "gebrennt", "gebrannt", "gebrunnen", 2}, // Mixed
    {"senden (to send)", "gesendet", "gesandt", "gesund", 2}, // Mixed
    {"können (can)", "gekonnt", "gekönnt", "gekann", 1},
    {"müssen (must)", "gemusst", "gemüsst", "gemuss", 1},
    {"wollen (want)", "gewollt", "gewollen", "gewillt", 1},
    {"dürfen (allowed to)", "gedurft", "gedürft", "gedarf", 1},
    {"mögen (like)", "gemogt", "gemocht", "gemögen", 2},
    {"fallen (to fall)", "gefallen", "gefellen", "gefullen", 1},
    {"gefallen (to please)", "gegefallen", "gefallen", "gefielen", 2},
    {"laufen (to run/walk)", "gelaufen", "geliefen", "geläuft", 1},
    {"tragen (to carry/wear)", "getragen", "getrugen", "getragt", 1},
    {"waschen (to wash)", "gewaschen", "gewuschen", "gewascht", 1},
    {"liegen (to lie down)", "gelegen", "geliegen", "gelag", 1},
    {"sitzen (to sit)", "gesessen", "gesitzen", "gesatzt", 1},
    {"fliegen (to fly)", "geflogen", "gefliegen", "geflogen", 1},
    {"ziehen (to pull/move)", "geziehen", "gezogen", "gezugen", 2},
    {"verlieren (to lose)", "verlieren", "verloren", "verluren", 2},
    {"gewinnen (to win)", "gewonnen", "gewinnen", "gewunnen", 1},
    {"schließen (to close)", "geschließen", "geschlossen", "geschluss", 2},
    {"beginnen (to begin)", "begonnen", "beginnen", "began", 1},
    {"vergessen (to forget)", "vergegerssen", "vergessen", "vergaß", 2},
    {"bekommen (to receive)", "gebekommen", "bekommen", "bekam", 2},
    {"rufen (to call)", "gerufen", "gerufen", "gerief", 1},
    {"heißen (to be named)", "geheißen", "gehießen", "geheißt", 1},
    {"schneiden (to cut)", "geschnitten", "geshneiden", "geschniet", 1},
    {"reiten (to ride horse)", "geritten", "gereiten", "gerieten", 1},
    {"steigen (to climb)", "gestiegen", "gesteigen", "gestiegenen", 1},
    {"scheinen (to shine)", "geschienen", "gescheint", "geschein", 1},
    {"lassen (to let)", "gelassen", "geliessen", "gelasst", 1},
    {"einladen (to invite)", "eingeleden", "eingeladen", "eingeludet", 2}
};

// LIST 3: SEPARABLE VERBS (Trennbare Verben) - "ge" goes in the middle!
Question separableVerbs[] = {
    {"aufstehen (to get up)", "aufgestanden", "aufstanden", "geaufstanden", 1},
    {"aufwachen (to wake up)", "aufgewacht", "aufgewachen", "geaufwacht", 1},
    {"einschlafen (to fall asleep)", "eingeschlafen", "eingeschlaft", "geeinschlafen", 1},
    {"einkaufen (to shop)", "eingekauft", "einkauft", "geeinkauft", 1},
    {"fernsehen (to watch TV)", "ferngesehen", "ferngeseht", "gefernsehen", 1},
    {"anrufen (to call)", "angerufen", "angerief", "anrufen", 1},
    {"abholen (to pick up)", "abgeholt", "abgeholen", "geabholt", 1},
    {"mitbringen (to bring along)", "mitgebracht", "mitgebringen", "gemitbringt", 1},
    {"mitkommen (to come along)", "mitgekommen", "mitkommen", "gemitkommen", 1},
    {"mitmachen (to participate)", "mitgemacht", "mitmachen", "gemitmacht", 1},
    {"zuhören (to listen to)", "zugehört", "zuhört", "gezuhören", 1},
    {"aufräumen (to clean up)", "aufgeräumt", "aufgeraumt", "geaufräumen", 1},
    {"anfangen (to start)", "angefangen", "angefingen", "geanfangen", 1},
    {"aufhören (to stop)", "aufgehört", "aufhoren", "geaufhört", 1},
    {"ausgehen (to go out)", "ausgegangen", "ausgehen", "geausgehen", 1},
    {"ankommen (to arrive)", "angekommen", "ankommt", "geankommen", 1},
    {"abfahren (to depart)", "abgefahren", "abfahren", "geabfahren", 1},
    {"einsteigen (to get in)", "eingestiegen", "einsteigen", "geeinstiegen", 1},
    {"aussteigen (to get out)", "ausgestiegen", "aussteigen", "geaussteigen", 1},
    {"umsteigen (to transfer)", "umgestiegen", "umsteigen", "geumstiegen", 1},
    {"anziehen (to dress)", "angezogen", "anzogen", "geanzogen", 1},
    {"ausziehen (to undress)", "ausgezogen", "auszogen", "geausziehen", 1},
    {"umziehen (to move house)", "umgezogen", "umzogen", "geumziehen", 1},
    {"vorlesen (to read aloud)", "vorgelesen", "vorlesen", "gevorlesen", 1},
    {"vorstellen (to introduce)", "vorgestellt", "vorstellen", "gevorstellen", 1},
    {"zumachen (to close)", "zugemacht", "zumachen", "gezumachen", 1},
    {"aufmachen (to open)", "aufgemacht", "aufmachen", "geaufmachen", 1},
    {"anmachen (to turn on)", "angemacht", "anmachen", "geanmachen", 1},
    {"ausmachen (to turn off)", "ausgemacht", "ausmachen", "geausmachen", 1},
    {"spazieren gehen (to stroll)", "spazieren gegangen", "gespazieren gehen", "spazieren gehen", 1}
};

// --- 3. Function to Shuffle Questions ---
// This uses the Fisher-Yates shuffle algorithm to randomize the array
void shuffleQuestions(Question *array, int n) {
    if (n > 1) {
        for (int i = n - 1; i > 0; i--) {
            // Pick a random index from 0 to i
            int j = rand() % (i + 1);
            
            // Swap array[i] with the element at random index j
            Question temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

// --- 4. Function to Run a Quiz Round ---
// This function takes the list of questions and how many there are.
void runQuiz(Question list[], int count, char *quizName) {
    int score = 0;
    int userAns;
    
    // Shuffle the questions before starting the quiz!
    shuffleQuestions(list, count);
    
    printf("\n=== Starting Quiz: %s ===\n", quizName);
    printf("There are %d verbs in this section. Questions are randomized!\n\n", count);
    
    // Loop through every question in the list
    for (int i = 0; i < count; i++) {
        printf("Question %d: %s\n", i + 1, list[i].verb);
        printf("   1) %s\n", list[i].opt1);
        printf("   2) %s\n", list[i].opt2);
        printf("   3) %s\n", list[i].opt3);
        printf("Your answer: ");
        scanf("%d", &userAns);
        
        if (userAns == list[i].correct) {
            printf("Correct!\n\n");
            score++;
        } else {
            // We need to print the right word.
            // We use a switch/case or simple logic to show the string.
            char *correctString;
            if (list[i].correct == 1) correctString = list[i].opt1;
            else if (list[i].correct == 2) correctString = list[i].opt2;
            else correctString = list[i].opt3;
            
            printf("Wrong. The correct answer was: %s\n\n", correctString);
        }
    }
    
    printf("--- SECTION FINISHED ---\n");
    printf("You scored %d out of %d.\n", score, count);
    printf("------------------------\n\n");
}

// --- 5. Main Function ---
int main() {
    // Seed the random number generator only once
    srand(time(0));
    
    int choice;
    
    // Calculate how many items are in each list automatically
    int countRegular = sizeof(regularVerbs) / sizeof(Question);
    int countIrregular = sizeof(irregularVerbs) / sizeof(Question);
    int countSeparable = sizeof(separableVerbs) / sizeof(Question);

    while(1) { // Loop forever until user exits
        printf("GERMAN VERB MASTER (A1)\n");
        printf("1. Regular Verbs (%d verbs)\n", countRegular);
        printf("2. Irregular Verbs (%d verbs)\n", countIrregular);
        printf("3. Separable Verbs (%d verbs)\n", countSeparable);
        printf("4. Exit\n");
        printf("Select a mode: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            runQuiz(regularVerbs, countRegular, "Regular Verbs");
        } 
        else if (choice == 2) {
            runQuiz(irregularVerbs, countIrregular, "Irregular Verbs");
        } 
        else if (choice == 3) {
            runQuiz(separableVerbs, countSeparable, "Separable Verbs");
        } 
        else if (choice == 4) {
            printf("Goodbye! Keep practicing.\n");
            break; // Break out of the loop
        } 
        else {
            printf("Invalid choice. Try again.\n\n");
        }
    }
    
    return 0;
}

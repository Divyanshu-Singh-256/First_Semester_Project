#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000
#define NUM_TEXTS 3

// Array of typing test paragraphs
const char *typing_texts[NUM_TEXTS] = {
    "The quick brown fox jumps over the lazy dog. This sentence contains every letter of the alphabet and is often used for typing practice. Typing speed is an essential skill in today's digital world.",
    
    "Programming is the art of telling another human what you want the computer to do. It requires patience, creativity, and logical thinking. Practice makes perfect, and every line of code you write brings you closer to mastery.",
    
    "The internet has revolutionized the way we communicate and share information. With just a few clicks, we can access knowledge from around the world. Technology continues to evolve at an unprecedented pace, reshaping society daily."
};

void display_welcome() {
    printf("\n");
    printf("================================================\n");
    printf("    WELCOME TO TYPING SPEED TESTER\n");
    printf("       Test Your Typing Skills Today!\n");
    printf("================================================\n");
    printf("\n");
}

void display_rules() {
    printf("RULES AND GUIDELINES:\n");
    printf("==================================================\n");
    printf("1. READ CAREFULLY: You will see a paragraph to type.\n");
    printf("   Make sure to type it exactly as shown, character by character.\n\n");
    
    printf("2. ACCURACY MATTERS: Every character counts!\n");
    printf("   Spelling mistakes, extra spaces, and punctuation errors\n");
    printf("   will affect your accuracy score.\n\n");
    
    printf("3. SPEED IS SECONDARY: Focus on accuracy first, then speed.\n");
    printf("   Your WPM (Words Per Minute) is calculated based on your typing.\n\n");
    
    printf("4. TIMING STARTS: The timer begins when you start typing\n");
    printf("   and ends when you press Enter.\n\n");
    
    printf("5. HAVE FUN: This is a test of skill, so relax and enjoy!\n");
    printf("========================================================\n\n");
}

void calculate_typing_speed(const char *original_text, const char *user_text, double time_taken) {
    int original_length = strlen(original_text);
    int user_length = strlen(user_text);
    int correct_chars = 0;

    // Remove newline from user input if present
    if (user_text[user_length - 1] == '\n') {
        user_length--;
    }

    for (int i = 0; i < original_length && i < user_length; i++) {
        if (original_text[i] == user_text[i]) {
            correct_chars++;
        }
    }

    double accuracy = ((double)correct_chars / original_length) * 100;
    double words_typed = (double)user_length / 5;
    double wpm = (time_taken > 0) ? (words_typed / time_taken) * 60 : 0;

    printf("\n");
    printf("================================================\n");
    printf("             YOUR RESULTS\n");
    printf("================================================\n\n");
    
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f WPM (Words Per Minute)\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Characters Typed: %d/%d correct\n\n", correct_chars, original_length);

    if (accuracy >= 95 && wpm >= 50) {
        printf("EXCELLENT! You're a typing master!\n");
    } else if (accuracy >= 90 && wpm >= 40) {
        printf("GREAT JOB! You're doing really well!\n");
    } else if (accuracy >= 80 && wpm >= 30) {
        printf("GOOD EFFORT! Keep practicing to improve!\n");
    } else {
        printf("KEEP PRACTICING! Every attempt makes you better!\n");
    }
    printf("\n");
}

int main() {
    char user_text[MAX_TEXT_LENGTH];
    clock_t start_time, end_time;
    double time_taken;
    int text_choice;

    display_welcome();
    display_rules();

    printf("SELECT YOUR PRACTICE TEXT:\n");
    printf("==================================================\n");
    for (int i = 0; i < NUM_TEXTS; i++) {
        printf("%d) %.60s...\n", i + 1, typing_texts[i]);
    }
    printf("==================================================\n");
    printf("Enter your choice (1-%d): ", NUM_TEXTS);
    scanf("%d", &text_choice);
    getchar(); // Consume newline after number

    if (text_choice < 1 || text_choice > NUM_TEXTS) {
        printf("Invalid choice! Using text 1 by default.\n");
        text_choice = 1;
    }

    const char *original_text = typing_texts[text_choice - 1];

    printf("\n");
    printf("================================================\n");
    printf("           PARAGRAPH TO TYPE\n");
    printf("================================================\n\n");
    printf("%s\n\n", original_text);
    printf("================================================\n");
    printf("Press Enter when you are READY to start the timer...\n");
    getchar();

    printf("\nSTART TYPING NOW!\n");
    printf("================================================\n\n");
    
    start_time = clock();
    fgets(user_text, MAX_TEXT_LENGTH, stdin);
    end_time = clock();

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    calculate_typing_speed(original_text, user_text, time_taken);
    
    printf("Thanks for using Typing Speed Tester!\n\n");
    
    return 0;
}
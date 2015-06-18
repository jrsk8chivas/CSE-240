#include <stdio.h>

#pragma warning(disable: 4996)

// Forward Declarations
int CaseOne(int, char*);
int CaseTwo(int, char*);
char* CaseThree(int, char*);
char* CaseFour(int, char*);
void CaseFive(int, char*);

// DO NOT CHANGE MAIN FUNCTION
void main() {
	int		value;
	char	CaseOneErrorType[256],
		CaseTwoErrorType[256],
		CaseThreeErrorType[256],
		CaseFourErrorType[256],
		CaseFiveErrorType[256];

	printf("Please enter an integer number between 65 to 90: ");
	scanf("%d", &value);

	printf("Initial state: %d \t Result: %d\n", value, CaseOne(value, CaseOneErrorType));
	printf("Initial state: %d \t Result: %d\n", value, CaseTwo(value, CaseTwoErrorType));
	printf("Initial state: %d \t Result: %s\n", value, CaseThree(value, CaseThreeErrorType));
	printf("Initial state: %d \t Result: %s\n", value, CaseFour(value, CaseFourErrorType));

	CaseFive(value, CaseFiveErrorType);
}

// [5pts] Fix the error
// Expected Result: double the value (ex: Value = 10, Result = 20)
int CaseOne(int value, char* ErrorType) {

	// [5pts] What type of error? (Syntactic, Semantic, or Contextual) 
	strcpy(ErrorType, "Contextual");

	return 2 * value;
}

// [5pts] Fix the error
// Expected Result: value ^ 2 (ex: Value = 20, Result: 400)
int CaseTwo(int value, char* ErrorType) {
	int result = 0;

	for (int index = 0; index < value; index++) {
		result += value;
	}

	// [5pts] What type of error? (Syntactic, Semantic, or Contextual)
	strcpy(ErrorType, "Semantic");

	return result;
}

// [5pts] Fix the error
// Expected Result: determine if value is even or odd (ex: Value = 11, Result = The inputted value is odd.)
char* CaseThree(int value, char* ErrorType) {
	char result[256];

	if (value % 2 == 0) {
		strcpy(result, "The inputted value is even.");
	}
	else {
		strcpy(result, "The inputted value is odd.");
	}

	// [5pts] What type of error? (Syntactic, Semantic, or Contextual)
	strcpy(ErrorType, "Semantic");

	return result;
}

// [5pts] Fix the error
// Expected Result: determine if the decimal value correspond to an alphabetic character.
// (ex: Value = 66, Result = "This is an alphabetic character.")
char* CaseFour(int value, char* ErrorType) {

	// [5pts] What type of error? (Syntactic, Semantic, or Contextual)
	strcpy(ErrorType, "Semantic");

	if ((65 <= value && value <= 90) || (97 <= value && value <= 122))
		return "This is an alphabetic character.";
	else
		return "Invalid character.";
}

// [5pts] Fix the errors
// Expected Result: Print the phrase, "Hello World - n", n number of times.  
// (ex: Value = 0, Result = "")
// (ex: Value = 2, Result = "Hello World - 1"
//							"Hello World - 2")
void CaseFive(int value, char* ErrorType) {
	int index = 0;

	while (index < value) {
		printf("Hello World - %d\n", index + 1);
		index++;
	}

	// [5pts] What type of error? (Syntactic, Semantic, or Contextual)
	strcpy(ErrorType, "Semantic");
}

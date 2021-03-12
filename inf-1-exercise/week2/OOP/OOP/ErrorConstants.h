#if !defined(ERROR_CONSTANTS_INCLUDED)
#define ERROR_CONSTANTS_INCLUDED

// #define ERR_CODE_NO_ERR 0

enum ErrorCode {
	ERR_CODE_NO_ERR = 0,
	ERR_CODE_WRONG_INPUT = 1,
	ERR_CODE_NO_MEM = 2
};

static int some_value = 10;

inline const char *getErrorMessage(ErrorCode code) {
	switch (code) {
	case ERR_CODE_NO_ERR: return "No error";
	case ERR_CODE_WRONG_INPUT: return "Wrong user input";
	case ERR_CODE_NO_MEM: return "Can't allocate memmory";
	}
	return "Unknown error";
}

#endif
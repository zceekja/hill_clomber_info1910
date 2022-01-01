#include "climber.h"

/*
 * Climber function
 *
 * return highest value
 */
int climber(
    int (*hills)(const void*),
    char* (*hills_format)(),
    size_t num_attempts)
{
    //Our buffer
    BYTE loca[128] = {0};
    BYTE* loc = &loca[0];

    //getting the format string
    char* format = hills_format();

    size_t attempt = 0;//use for count attempt
    int best = -1; // set initial return value to -1 (FAIL)
    int count = 0; // use for count format sting
    int item_loc[65]; // use for store position of format string
    int item_count = 0; //use for count number of item in format string (empty space,%c, %d,%f)
    int results[4] = {0, 0, 0, 0}; // array of last 4 results

    //set initial value
    int int_a = 1;
    char char_a = 'a';
    double double_a = 1;
    int* int_ptr = &int_a;
    char* char_ptr =&char_a;
    double* double_ptr = &double_a;

    // variable to store previous result
    int store_int = 1;
    char store_char = 'a';
    double store_double = 1;
    int* sint_ptr = &store_int;
    char* schar_ptr =&store_char;
    double* sdouble_ptr =&store_double;

    int move = 0;
    item_loc[0] = 0;
    int algorithm = 1;
    while( attempt < num_attempts)
    {
        //insert  initial value to buffer corresponding to format string
        if (attempt == 0)
        {   while(*format)
            {
                if (*format == '%')
                {
                    if (*(format + 1)== 'c')
                    {
                        *loc = 'a';
                        loc++;
                        count++;
                    }
                    else if(*(format + 1) == 'd')
                    {
                        *((int*)loc) = 1;
                        loc+=4;
                        count+=4;
                    }
                    else if (*(format + 1) == 'f')
                    {
                        *((double*)loc) = 1;
                        loc += 8;
                        count += 8;
                    }
                    item_count++;
                    item_loc[item_count] = count;
                    format+= 2;
                }
                else if (*format == ' ')
                {
                    item_count++;
                    count++;
                    item_loc[item_count] =count;
                    loc++;
                    format++;
                }
            }
        }
        // for second attepmt onward , apply algorithm for better result each time
        else if (attempt > 0)
        {
            // restore previous result and move to next value
            if (algorithm == 3)
            {
                if (item_loc[move + 1] - item_loc[move] == 8)
                {
                    *((double*)(loc + item_loc[move])) = store_double;
                }
                else if (item_loc[move + 1] - item_loc[move] == 4)
                {
                    *((int*)(loc + item_loc[move])) = store_int;
                }
                else if (item_loc[move + 1] - item_loc[move] == 1)
                {
                    *(loc+item_loc[move]) = store_char;
                }
                move++;
                reset(results, int_ptr, char_ptr, double_ptr, sint_ptr, schar_ptr, sdouble_ptr);
                algorithm = 1;
            }

            //check for space
            while ((item_loc[move + 1] - item_loc[move] == 1) && (*(loc + item_loc[move]) == '\0'))
            {
                move++;
            }

            //algorithm number 1
            if (algorithm == 1)
            {
                if (item_loc[move + 1] - item_loc[move] == 8)
                {
                    *((double*)(loc + item_loc[move])) = double_algo1(double_ptr, sdouble_ptr);
                }
                else if (item_loc[move + 1] - item_loc[move] == 4)
                {
                    *((int*)(loc + item_loc[move])) = int_algo1(int_ptr, sint_ptr);
                }
                else if (item_loc[move + 1]- item_loc[move] == 1)
                {
                    *(loc + item_loc[move]) = char_algo1(char_ptr, schar_ptr);
                }
            }

            //algorithm number 2
            else if (algorithm == 2)
            {
                if (item_loc[move + 1] - item_loc[move] == 8)
                {
                    *((double*)(loc + item_loc[move])) = double_algo2(double_ptr, sdouble_ptr);
                }
                else if (item_loc[move + 1] - item_loc[move] == 4)
                {
                    *((int*)(loc + item_loc[move])) = int_algo2(int_ptr, sint_ptr);
                }
                else if (item_loc[move+1] - item_loc[move] == 1)
                {
                    *(loc + item_loc[move]) = char_algo2(char_ptr, schar_ptr);
                }
            }
        }

        int result = hills(&loca[0]);
        //record best result
        if (result > best)
        {
            best = result;
        }
        attempt++;
        loc = &loca[0];  // reset pointer to buffer

        //record and shift results
        results[0] = results[1];
        results[1] = results[2];
        results[2] = results[3];
        results[3] = result;
        algorithm = result_check(results); //compare result and pick algorithm
    }
    return best;
}


//return 1 for algorithm 1
//return 2 for algorithm 2
//return 3 for exit/move to next

int result_check(int results[])
{
    if (results[2] == 0)
    {
        //nothing to compare just return 1
        return 1;
    }
    else if (results[1] == 0)
    {
        if (results[3] > results[2])
        {
            //1 is right direction keep going with 1
            return 1;
        }
        else if (results[3] < results[2])
        {
            //oh it getting worst go opposite lets try 2!
            return 2;
        }
    }
    else if (results[0] == 0)
    {
        if (results[3] > results[2])
        {
            if (results[2] > results[1])
            {
                // 1 is superb keep going going
                return 1;
            }
            else if (results[2] < results[1])
            {   // 2 is doing well keep going
                return 2;
            }
        }
        else if (results[3] < results[2])
        {
            if (results[2] > results[1])
            {
                // more less more , let exit!
                return 3;
            }
        }

        return 3;
    }
    else
    {
        if (results[3] > results[2])
        {
            if (results[2] > results[1])
            {
                if (results[1] > results[0])
                {
                    // 1 is unstopable keep going
                    return 1;
                }
                else if (results[1] < results[0])
                {
                    // 2 still good
                    return 2;
                }
            }
        }

    }
    return 3; //its getting worst, move on
}

//reset results record
void reset(int results[],int* a, char* b, double* c, int* d, char* e, double* f)
{
    results[2] = 0;
    results[1] = 0;
    results[0] = 0;
    *a = 1;
    *b = 'a';
    *c = 1;
    *d = 1;
    *e = 'a';
    *f = 1;

}



// int positive algo
int int_algo1(int* a ,int* s)
{
    *s = *a;
    *a -= 5;
     // to increase performance change 5 to 4,3,2 or 1
     // but if attempt is not high enough it will fail

    return *a;
}

//int negative algo
int int_algo2(int* a, int* s)
{
    *s = *a;
    *a += 5;
    // to increase performance change 5 to 4,3,2 or 1(best perforamce)
    // but if attempt is not high enough it will be fail

    return *a;
}

//char positive algo
char char_algo1(char* a, char* s)
{
    *s = *a;
    *a += 1;
    //increment by 1(best performance)
    return *a;
}

//char negative algo
char char_algo2(char* a, char* s)
{
    *s = *a;
    *a -= 1;
    //decrement by 1(best performance)
    return *a;
}

//double positive algo
double double_algo1(double* a, double* s)
{
    *s = *a;
    *a += *a;
    //Since this is double, and you may expect high value
    //, therefore I double value each time
    return *a;
}
//double negative algo
double double_algo2(double* a, double* s)
{
    *s = *a;
    if (*a > 0)
    {
        *a = -*a; // convert to negative
    }
    else
    {
        *a += *a; // double negative
    }

    return *a;
}

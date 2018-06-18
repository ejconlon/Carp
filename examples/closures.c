#include <stdio.h>
#include <stdlib.h>

// (defn main []
//   (let [x 123
//         f (fn [] (+ 1 x))]
//      (f)))

// Environment for this particular lambda
typedef struct {
    int x;
} Env_main_0;

// The one struct needed for any lambda with signature (Fn [] Int)
typedef struct Closure__Unit_Int {
    int (*callback)(void *closure);
    void *env;
} Closure__Unit_Int;

// The body of the lambda, but lifted to its own function. Takes the environment as a first argument.
int lifted_lambda_main_0(Env_main_0 *env) {
    return 1 + env->x; // simplified for readability
}

// Deleter for this particular closure
void delete_Closure__Unit_Int__Int(Closure__Unit_Int closure) {
    free(closure.env);
}

int main() {
    // let x
    int x = 123;
    // let f
    Env_main_0 *env_0 = malloc(sizeof(Env_main_0));
    env_0->x = x;
    Closure__Unit_Int f = {
        .callback = (void*)lifted_lambda_main_0,
        .env = env_0
    };
    // call f
    int _1 = f->callback(f->env);
    // delete f
    delete_Closure__Unit_Int__Int(f);
    return _1;
}

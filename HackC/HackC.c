#include "include/console/console.h"
#include "include/memory/memory.h"
#include "include/interfaces/interfaces.h"
#include "include/hooking/hooks.h"

// -----------------------------------------------------
// my first big only C project that is nicely organized,
// both structure and code wise. it might have some flaws
// on code design, and yeah, go ahead and blame me for that
// but I'm still learning as I mostly wrote C in a fork of
// it to make San Andreas Multiplayer servers, and as you
// could expect, there was no code standard, at least in
// backwater communities such as the ones that I were in
// as a 10-11 year old, not even teenager but outright
// child with no background in programming but still an
// aspiring one nonetheless. C seems fun and this is why
// I'm doing it also within a field that I am already
// used to work within, to not have more issues with the
// analysis part more than the language part
// which should also not be that big considering my
// main programming language is C++, main thing I
// observed were some clear syntax nitpicking issues,
// externalization errors, memory management is also rather weird
// as my ass is used to either new, delete and smart pointers.

// maybe useful resources:
// - https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#src.header-placement
// - https://www.quora.com/What-are-some-C-programming-best-practices
// -----------------------------------------------------

BOOL APIENTRY DllMain(_In_ HMODULE module, _In_ DWORD reason_for_call, _In_opt_ LPVOID reserved)
{
    switch (reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        console_initialize();
        memory_initialize();
        interfaces_initialize();
        hooking_initialize();
        break;
    case DLL_PROCESS_DETACH:
        console_release();

        // avoid crashes, considering we will
        // stick to our memory structure
        // to initialize signatures and the such,
        // our members will be nullified and in the
        // meantime they may be used in
        // a) entity code
        // b) literal hooks, hook functions, etc
        // c) hook tables
        // thus, we first get rid of hooks, then proceed
        // in whatever order you may for the next 2, nothing is
        // dependend on the other in those cases
        hooking_release();

        memory_release();
        interfaces_release();
        break;
    }
    return TRUE;
}
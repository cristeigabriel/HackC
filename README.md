# HackC
HackC is an in-early development, opensource, multihack written in the C programming language, my first serious project written in bare C.
HackC is inspired by [**Anubis**](https://github.com/danielkrupinski/Anubis/tree/master/Anubis), a CS:GO multihack written in C, which is seemingly abandoned, at this time, and also uses parts of code from it within regulations of the MIT license, alongside also making changes to it.

# Guidelines
HackC is written in **snake_case**, and follows [**this**](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#tld) file structure.

Due to lack of namespaces, to compensate for namespaces, we use keywords for functions to be able to locate them and avoid redefinitions,
example:
- HackC/include/interfaces/sdk/client.h
  - "**client_get_all_classes**"
  - "**client_dispatch_user_message**"
- HackC/include/interfaces/sdk/engine.h
  - "**engine_client_get_player_info**"
  - "**engine_client_get_player_for_uid**"

etc...

For type definitions, we add the suffix '**t**' in their names, to signal the fact that an element is specified to be a type definition.

Signatures should be created as "code patterns", unless one wants to implement their own IDA style signature finder, or adapt the existing one.

# Compability
HackC has been tested on Windows 10 (**ver. 2004**) and should work on every other one, and is planned to be ported to Linux at one (not so near) point in time.

# Contributions
If you feel that something doesn't follow best practices, please open a Pull Request with your change, or, open an Issue where someone will look at it and fix it.

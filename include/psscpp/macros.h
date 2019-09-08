/** Common utility macros
 *
 *  \file include/psscpp/macros.h
 *  \author Dr. Philip Salvaggio (salvaggio.philip@gmail.com)
 *  \date 08 Sep 2019
 */

/// Selects a macro based on the number of arguments
#define PSS_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME

/// Helper macro for PSS_TEMPLATE_PARAMS
/// \{
#define PSS_TEMPLATE_PARAMS1(x) class x
#define PSS_TEMPLATE_PARAMS2(x, ...) class x, PSS_TEMPLATE_PARAMS1(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS3(x, ...) class x, PSS_TEMPLATE_PARAMS2(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS4(x, ...) class x, PSS_TEMPLATE_PARAMS3(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS5(x, ...) class x, PSS_TEMPLATE_PARAMS4(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS6(x, ...) class x, PSS_TEMPLATE_PARAMS5(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS7(x, ...) class x, PSS_TEMPLATE_PARAMS6(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS8(x, ...) class x, PSS_TEMPLATE_PARAMS7(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS9(x, ...) class x, PSS_TEMPLATE_PARAMS8(__VA_ARGS__)
#define PSS_TEMPLATE_PARAMS10(x, ...) class x, PSS_TEMPLATE_PARAMS9(__VA_ARGS__)
/// \}

/// Takes a list of template parameter names and prepends "class" to each one
#define PSS_TEMPLATE_PARAMS(...)                                          \
  PSS_GET_MACRO(__VA_ARGS__, PSS_TEMPLATE_PARAMS10, PSS_TEMPLATE_PARAMS9, \
                PSS_TEMPLATE_PARAMS8, PSS_TEMPLATE_PARAMS7,               \
                PSS_TEMPLATE_PARAMS6, PSS_TEMPLATE_PARAMS5,               \
                PSS_TEMPLATE_PARAMS4, PSS_TEMPLATE_PARAMS3,               \
                PSS_TEMPLATE_PARAMS2, PSS_TEMPLATE_PARAMS1)(__VA_ARGS__)

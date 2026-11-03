typedef struct {
    int x;
    int y;
} vec2_t;
/// @brief Multiplying vectors
void vector2_mul(vec2_t *c, vec2_t a, vec2_t b);
/// @brief Adding vectors
void vector2_plus(vec2_t *c, vec2_t a, vec2_t b);
/// @brief Minus vectors
void vector2_min(vec2_t *c, vec2_t a, vec2_t b);
/// @brief Dividing vectors
void vector2_div(vec2_t *c, vec2_t a, vec2_t b);
/// @brief Calculates the distance between vector 'a' and 'b'.
void vector2_dist(vec2_t *c, vec2_t a, vec2_t b);

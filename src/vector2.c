#include <tlogger.h>
#include <vector2.h>

void vector2_mul(vec2_t *c, vec2_t a, vec2_t b) {
    c->x = a.x * b.x;
    c->y = a.y * b.y;
}
void vector2_plus(vec2_t *c, vec2_t a, vec2_t b) {
    c->x = a.x + b.x;
    c->y = a.y + b.y;
}
void vector2_min(vec2_t *c, vec2_t a, vec2_t b) {
    c->x = a.x - b.x;
    c->y = a.y - b.y;
}
void vector2_div(vec2_t *c, vec2_t a, vec2_t b) {
    if (a.x == 0 || a.y == 0 || b.x == 0 || b.y == 0) {
        logm(WARN, "Can't divide by zero.");
        return;
    }
    c->x = a.x / b.x;
    c->y = a.y / b.y;
}

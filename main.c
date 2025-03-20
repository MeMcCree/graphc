#include "stdio.h"
#include "stdlib.h"

typedef struct {
	double x, y;
} vec2_t;

typedef struct {
	double x, y;
} point_t;

typedef struct {
	point_t a, b;
} segment_t;

typedef struct {
	double a, b, c;
} line_t;

typedef struct {
	line_t ray;
	line_t half;
} ray_t;

typedef struct {
	vec2_t center;
	double radius;
} circle_t;

typedef struct {
	unsigned int width, height; 
	unsigned int bg_color;
	vec2_t units;
} canvas_t;

#define MAX_SHAPES 256

point_t points[MAX_SHAPES];
unsigned int points_cnt = 0;

segment_t segments[MAX_SHAPES];
unsigned int segments_cnt = 0;

line_t lines[MAX_SHAPES];
unsigned int lines_cnt = 0;

ray_t rays[MAX_SHAPES];
unsigned int rays_cnt = 0;

circle_t circles[MAX_SHAPES];
unsigned int circles_cnt = 0;

void append_point(point_t p) {
	if (points_cnt == MAX_SHAPES) {
		fprintf(stderr, "[ERR] Exceeded maximum amount of points.\n");
		exit(1);
	}
	points[points_cnt++] = p;
}

void append_segment(segment_t p) {
	if (segments_cnt == MAX_SHAPES) {
		fprintf(stderr, "[ERR] Exceeded maximum amount of segments.\n");
		exit(1);
	}
	segments[segments_cnt++] = p;
}

void append_line(line_t p) {
	if (lines_cnt == MAX_SHAPES) {
		fprintf(stderr, "[ERR] Exceeded maximum amount of lines.\n");
		exit(1);
	}
	lines[lines_cnt++] = p;
}

void append_ray(ray_t p) {
	if (rays_cnt == MAX_SHAPES) {
		fprintf(stderr, "[ERR] Exceeded maximum amount of rays.\n");
		exit(1);
	}
	rays[rays_cnt++] = p;
}

void append_circle(circle_t p) {
	if (circles_cnt == MAX_SHAPES) {
		fprintf(stderr, "[ERR] Exceeded maximum amount of circles.\n");
		exit(1);
	}
	circles[circles_cnt++] = p;
}

vec2_t vec2_pts(point_t a, point_t b) {
	return (vec2_t){.x = b.x - a.x, .y = b.y - a.y};
}

vec2_t vec2_segm(segment_t s) {
	return (vec2_t){.x = s.b.x - s.a.x, .y = s.b.y - s.a.y};
}

line_t line_pts(point_t a, point_t b) {
	line_t res;
	res.a = -(b.y - a.y);
	res.b = b.x - a.x;
	res.c = -(a.x*res.a + a.y*res.b);
	return res;
}

line_t line_segm(segment_t s) {
	line_t res;
	res.a = -(s.b.y - s.a.y);
	res.b = s.b.x - s.a.x;
	res.c = -(s.a.x*res.a + s.a.y*res.b);
	return res;
}

line_t line_par_pt(line_t l, point_t p) {
	return (line_t){.a = l.a, .b = l.b, .c = -(p.x*l.a + p.y*l.b)};
}

int main(int argc, char* argv[]) {
	return 0;
}
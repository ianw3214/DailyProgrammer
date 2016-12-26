# Program that calculates area of overlapping rectangle(s) for Daily Programming Challenge
# INTERMEDIATE 296

def get_overlapping_area(rectangles):
    """Return the area of the rectangle created by two or more overlapping
    rectangles

    @type rectangles: list[(float, float, float, float)]
    @rtype: float
    """
    curr_rect = (rectangles[0][0], rectangles[0][1], rectangles[0][2],
                 rectangles[0][3])
    for rect in rectangles[1:]:
        curr_rect = compare_area(curr_rect, rect)
        if curr_rect == (0, 0, 0, 0):
            return 0.0
    width = curr_rect[2] - curr_rect[0]
    height = curr_rect[3] - curr_rect[1]
    return round(width * height, 10)


def compare_area(rect1, rect2):
    """Return the resulting rectangle by overlapping two rectangles

    @type rect1: (float, float, float, float)
    @type rect2: (float, float, float, float)
    @rtype: (float, float, float, float)
    """
    # First find the rectangles with top left/bottom right corners
    x1_1, y1_1, x2_1, y2_1 = rect1
    x1_2, y1_2, x2_2, y2_2 = rect2
    if x1_1 > x2_1:
        x1_1, x2_1 = x2_1, x1_1
    if y1_1 > y2_1:
        y1_1, y2_1 = y2_1, y1_1
    if x1_2 > x2_2:
        x1_2, x2_2 = x2_2, x1_2
    if y1_2 > y2_2:
        y1_2, y2_2 = y2_2, y1_2
    # Find the new coordinates
    new_x1 = max(x1_1, x1_2)
    new_y1 = max(y1_1, y1_2)
    new_x2 = min(x2_1, x2_2)
    new_y2 = min(y2_1, y2_2)
    if new_x2 <= new_x1 or new_y2 <= new_y1:
        return (0, 0, 0, 0)
    return (new_x1, new_y1, new_x2, new_y2)


if __name__ == "__main__":
    assert get_overlapping_area([(0, 0, 2, 2), (1, 1, 3, 3)]) == 1.0
    assert get_overlapping_area([(-3.5, 4, 1, 1), (1, 3.5, -2.5, -1)]) == 8.75
    assert get_overlapping_area([(-4, 4, -0.5, 2), (0.5, 1, 3.5, 3)]) == 0.0
    assert get_overlapping_area([(-3, 0, 1.8, 4), (1, 1, -2.5, 3.6), (-4.1, 5.75, 0.5, 2), (-1.0, 4.6, -2.9, -0.8)]) == 2.4

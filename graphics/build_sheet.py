import fitz

MM = 72.0 / 25.4

PAGE_W, PAGE_H = 612.0, 792.0  # US Letter, points
IMG_SIZE = 24.0 * MM
GAP = 4.0 * MM

grid_w = IMG_SIZE * 2 + GAP
grid_h = IMG_SIZE * 2 + GAP
x0 = (PAGE_W - grid_w) / 2
y0 = (PAGE_H - grid_h) / 2

cells = [
    ("pink.png", 0, 0),
    ("pink.png", 1, 0),
    ("blue.png", 0, 1),
    ("blue.png", 1, 1),
]

doc = fitz.open()
page = doc.new_page(width=PAGE_W, height=PAGE_H)

for fname, col, row in cells:
    x = x0 + col * (IMG_SIZE + GAP)
    y = y0 + row * (IMG_SIZE + GAP)
    rect = fitz.Rect(x, y, x + IMG_SIZE, y + IMG_SIZE)
    page.insert_image(rect, filename=fname, keep_proportion=False)

doc.save("to_print.pdf")
print("wrote to_print.pdf")

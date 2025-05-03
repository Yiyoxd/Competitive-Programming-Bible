# 🧠 Comprehensive Geometry Reference for Competitive Programming (ICPC)

This document covers essential **formulas**, **properties**, and **computational techniques** for solving geometry problems in programming contests like ICPC, Codeforces, and AtCoder.

---

## 📐 2D Geometry: Plane Figures

### 🔷 Square
- **Area**: `A = side²`
- **Perimeter**: `P = 4 × side`
- **Diagonal**: `d = side × √2`

### 🔷 Rectangle
- **Area**: `A = width × height`
- **Perimeter**: `P = 2 × (width + height)`
- **Diagonal**: `d = √(w² + h²)`

### 🔷 Triangle
- **Basic Area**: `A = (base × height) / 2`
- **Heron's Formula**:
  ```
  s = (a + b + c) / 2
  A = √(s(s - a)(s - b)(s - c))
  ```
- **Trigonometric Area**: `A = (1/2)ab sin(C)`
- **Equilateral Triangle**:
  - Area: `A = (√3 / 4) × a²`
  - Height: `h = (√3 / 2) × a`

### 🔷 Circle
- **Area**: `A = π × r²`
- **Circumference**: `C = 2π × r`
- **Arc Length**: `L = r × θ` (θ in radians)
- **Sector Area**: `A = (θ / 2) × r²`
- **Segment Area**: `A = (r²/2)(θ - sin(θ))`

### 🔷 Trapezoid (Trapezium)
- **Area**: `A = ((a + b) × h) / 2`

### 🔷 Parallelogram
- **Area**: `A = base × height`
- **Area with vectors**: `A = |u × v|`

### 🔷 Rhombus
- **Area**: `A = (d₁ × d₂) / 2`

### 🔷 Regular Polygon
- **Interior Angle**: `((n − 2) × 180°) / n`
- **Area**: `A = (n × a²) / (4 × tan(π / n))`
- **Diagonals**: `D = n(n - 3) / 2`

---

## 📊 Coordinate Geometry and Vectors

### 🔹 Distance
```math
d = sqrt((x₂ − x₁)² + (y₂ − y₁)²)
```

### 🔹 Midpoint
```math
M = ((x₁ + x₂)/2 , (y₁ + y₂)/2)
```

### 🔹 Point-Slope Form
```math
y − y₁ = m(x − x₁)
```

### 🔹 Dot Product
- `A · B = ax × bx + ay × by`
- `A · B = |A||B| cos(θ)`

### 🔹 Cross Product (2D)
- `A × B = ax × by − ay × bx`

### 🔹 Triangle Area (with vectors)
- `A = 0.5 × |A × B|`

### 🔹 Angle Between Vectors
- `cos(θ) = (A · B) / (|A||B|)`

### 🔹 Projection of A onto B
- `proj_B(A) = (A · B / |B|²) × B`

---

## 📘 Trigonometry

### 🔹 Law of Sines
```math
a / sin(A) = b / sin(B) = c / sin(C) = 2R
```

### 🔹 Law of Cosines
```math
c² = a² + b² − 2ab cos(C)
```

### 🔹 Useful Identities
- `sin²x + cos²x = 1`
- `tan(x) = sin(x)/cos(x)`
- `sin(2x) = 2sin(x)cos(x)`

---

## 🧊 Solid Geometry: 3D Figures

### 🔸 Cube
- **Volume**: `V = a³`
- **Surface Area**: `A = 6a²`

### 🔸 Rectangular Prism (Cuboid)
- **Volume**: `V = l × w × h`
- **Surface Area**: `A = 2(lw + lh + wh)`

### 🔸 Sphere
- **Volume**: `V = (4/3)πr³`
- **Surface Area**: `A = 4πr²`

### 🔸 Cylinder
- **Volume**: `V = πr²h`
- **Surface Area**: `A = 2πr(r + h)`

### 🔸 Cone
- **Volume**: `V = (1/3)πr²h`
- **Surface Area**: `A = πr(r + l)`  
  *(l = slant height = √(r² + h²))*

### 🔸 Pyramid
- **Volume**: `V = (1/3) × BaseArea × height`

---

## 💻 Computational Geometry

### 🔹 Shoelace Formula (Polygon Area)
```math
A = (1/2) × |∑(xi·yi+1 − xi+1·yi)|
```

### 🔹 Orientation Test (Cross Product)
```cpp
int cross(int ax, int ay, int bx, int by) {
    return ax * by - ay * bx;
}
```
- Positive: counter-clockwise turn  
- Negative: clockwise turn  
- Zero: collinear

### 🔹 Point in Triangle (with cross)
```cpp
bool inside = sameSign(cross(AB, AP), cross(BC, BP), cross(CA, CP));
```

### 🔹 Convex Hull (Graham Scan or Andrew’s)
- Sort points
- Construct upper/lower hull with `cross`

### 🔹 Point in Polygon (Ray Casting or Winding Number)

---

## 🔁 Geometric Transformations

### 🔹 Rotation
```math
x' = x cos(θ) − y sin(θ)  
y' = x sin(θ) + y cos(θ)
```

### 🔹 Reflection (over y = mx + b)
- Use orthogonal projection formulas

---

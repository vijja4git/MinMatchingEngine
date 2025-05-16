# ✅ MiniMatchingEngine: Full Setup & Git/GitHub Documentation

### 📁 Project Goal:

Build a C++ limit order matching engine, set up CMake, use SSH for GitHub, and manage the project with clean Git practices.

---

## ⚙️ 1. Project Structure Setup

```bash
mkdir -p ~/Documents/Trading/MiniMatchingEngine
cd ~/Documents/Trading/MiniMatchingEngine
mkdir src
touch src/main.cpp src/OrderBook.cpp src/OrderBook.h
touch CMakeLists.txt
```

---

## 📄 2. Add C++ Code

Paste your implementation of:

* `src/OrderBook.h`
* `src/OrderBook.cpp`
* `src/main.cpp`

---

## 💪 3. CMake Configuration

Edit `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(MiniMatchingEngine)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)

add_executable(matching_engine
    src/main.cpp
    src/OrderBook.cpp
)
```

---

## 🧪 4. Build & Run Project

```bash
rm -rf build              # Clean any previous build
mkdir build
cd build
cmake ..
make
./matching_engine
```

---

## 🔐 5. Set Up SSH Key for GitHub (One-Time Setup)

### Check if key exists:

```bash
ls ~/.ssh
```

### If not, generate one:

```bash
ssh-keygen -t ed25519 -C "vijja4git@gmail.com"
```

(Just press Enter through the prompts, no passphrase)

### Add it to GitHub:

```bash
cat ~/.ssh/id_ed25519.pub
```

* Copy the output and paste into GitHub:
  [https://github.com/settings/keys](https://github.com/settings/keys)

### Test:

```bash
ssh -T git@github.com
```

You should see:

```
Hi vijja4git! You've successfully authenticated...
```

---

## 🧑‍💻 6. Initialize Git Repo and Commit

Go to your project root:

```bash
cd ~/Documents/Trading/MiniMatchingEngine

git init
git remote add origin git@github.com:vijja4git/MinMatchingEngine.git

git add src/ CMakeLists.txt
git commit -m "Initial commit: Working matching engine"
```

---

## 🚀 7. Push to GitHub via SSH

```bash
git push --set-upstream origin main
```

If you see this error:

```
! [rejected] main -> main (fetch first)
```

Fix with:

```bash
git pull --rebase origin main
# If you had uncommitted changes:
git add .
git commit -m "Save work before rebase"
git pull --rebase origin main
```

Then push again:

```bash
git push
```

---

## 📦 8. README Setup

Create `README.md`:

```bash
touch README.md
```

Paste in your project description and usage instructions, then:

```bash
git add README.md
git commit -m "Add README"
git push
```

---

## 🔍 9. Final Verification

Your GitHub repo should now show:

* `src/` with your `.cpp` and `.h` files
* `CMakeLists.txt`
* `README.md`
* Build instructions and sample output

---

## ✅ Summary of Most-Used Commands

```bash
# Start project
mkdir -p MiniMatchingEngine/src
cd MiniMatchingEngine

# Build
rm -rf build && mkdir build && cd build && cmake .. && make

# Run
./matching_engine

# Git setup
git init
git remote add origin git@github.com:vijja4git/MinMatchingEngine.git
git add .
git commit -m "message"
git push --set-upstream origin main

# SSH test
ssh -T git@github.com
```

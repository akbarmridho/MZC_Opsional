# MZC_Opsional Candy Land
Tugas Besar 1 IF2210 Pemrograman Berorientasi Objek

## Deskripsi Program

Dalam rangka merayakan pesta panen gula di kerajaan permen, akan diadakan kompetisi massal permainan kartu ala Kerajaan Permen. Ratu kerajaan permen ingin mencari pemain kartu terhebat di kerajaannya. Namun karena Ratu tidak bisa memantau permainan satu-persatu, kalian diminta untuk membuatkan sistem agar permainan dapat berjalan dengan adil. Bantulah ratu kerajaan permen untuk membuatkan permainan ala kerajaan permen.

## Anggota

1. Fakhri Muhammad Mahendra (13521045)
2. Razzan Daksana Yoni (13521087)
3. Kenneth Ezekiel Suprantoni (13521089)
4. Akbar Maulana Ridho (13521093)
5. Arsa Izdihar Islam (13521101)
   
## Permainan tambahan

Selain candy land, kami juga membuat game bonus yang bernama cangkulan.

## Setup and Installation

1. Clone repo

```
git clone git@github.com:akbarmridho/MZC_Opsional.git
```

1. Compile the program

Pastikan gcc dan cmake telah terinstall. Buka terminal pada folder project, lalu buat Makefiles dengan perintah

### Linux

Buka terminal pada folder project, lalu buat Makefiles dengan perintah

```
cmake -B build .
```

Setelah berhasil, pindah ke folder build

```
cd build
```

Jalankan makefile

```
make
```

3. Run the app

Pada folder build, jalankan perintah

```
./MZC_Opsional
```

## Branching and Commit Messages

Setiap membuat branch baru harus ambil base dari `main`. Untuk penamaan commit dan branch mengikuti format berikut.
Format branch: `<type>/<title>`
Format commit: `<type>: <subject>`
Penamaan menggunakan kebab case

Untuk type mengikuti semantic berikut.

- `feat`: (new feature for the user, not a new feature for build script)
- `fix`: (bug fix for the user, not a fix to a build script)
- `docs`: (changes to the documentation)
- `style`: (formatting, missing semi colons, etc; no production code change)
- `refactor`: (refactoring production code, eg. renaming a variable)
- `test`: (adding missing tests, refactoring tests; no production code change)
- `chore`: (updating grunt tasks etc; no production code change)

## Pull Request

Untuk melakukan pull request perlu mengikuti flow berikut.

1. Saat selesai mengerjakan task, boleh langsung melakukan PR ke main dengan membuat PR dari branch pengerjaan ke `main`
2. Merge untuk branch `main` boleh dilakukan setelah mendapatkan persetujuan dari minimal satu orang anggota kelompok
   lainnya.
3. Penamaan PR mengikuti format penamaan branch.
4. Pada deskripsi PR mohon menyertakan format berikut.

- What PR About?
- Is there any problems in this PR?

5. Mohon utamakan komunikasi, terutama untuk approval.
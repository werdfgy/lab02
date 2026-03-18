# Homework
## Сделал: Жданов Владимир ИУ8-23
### Part I

[](https://github.com/tp-labs/lab02#part-i)

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
```bash
$ git init
Initialized empty Git repository in /home/user/lab/lab02/.git/
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)
$ git branch -m main
$ git remote add origin https://github.com/werdfgy/lab02.git
$ git push -u origin main
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 220 bytes | 220.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/werdfgy/lab02.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.
```
3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
   ``` bash
   $ cat > hello_world.cpp <<'EOF'
> #include <iostream>
include> #include <string>
> using namespace std;
in() {>
> int main() {
Enter > string name;
> cout<<"Enter your name: ";
> cin>>name;
t<<"H> cout<<"Hello world from "<<name<<endl;
> return 0;
> }
> EOF
   ```
4. Добавьте этот файл в локальную копию репозитория.
   ``` bash
   $ git add hello_world.cpp
   ```
5. Закоммитьте изменения с _осмысленным_ сообщением.
   ``` bash
   git commit -m "add hello_world with bad code style"
[main e8b6c91] add hello_world with bad code style
 1 file changed, 11 insertions(+)
 create mode 100644 hello_world.cpp
   ```
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
   ``` bash
   $ nano hello_world.cpp
   $ cat hello_world.cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
   ```
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
``` bash
   $ git commit -am "improve hello_world"
[main 44de54c] improve hello_world
 1 file changed, 5 insertions(+), 6 deletions(-)
```
   -a Автоматически добавляет в коммит все изменения в уже отслеживаемых файлах
8. Запуште изменения в удалёный репозиторий.
``` bash
   $ git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 813 bytes | 406.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/werdfgy/lab02.git
   4e586e6..44de54c  main -> main
```
9. Проверьте, что история коммитов доступна в удалёный репозитории.
``` bash
   $ git log --oneline --graph
* 44de54c (HEAD -> main, origin/main) improve hello_world
* e8b6c91 add hello_world with bad code style
* 4e586e6 added README.md
```
![[Pasted image 20260318192715.png]]
### Part II

[](https://github.com/tp-labs/lab02#part-ii)

**Note:** _Работать продолжайте с теми же репоззиториями, что и в первой части задания._

1. В локальной копии репозитория создайте локальную ветку `patch1`.
``` bash
   $ git checkout -b patch1
Switched to a new branch 'patch1'
```
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
``` bash
   $ nano hello_world.cpp
   $ cat hello_world.cpp
#include <iostream>
#include <string>

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello world from " << name << std::endl;

    return 0;
}
```
3. **commit**, **push** локальную ветку в удалённый репозиторий.
``` bash
   $ git commit -am "fix code style in patch1"
[patch1 66bd965] fix code style in patch1
 1 file changed, 3 insertions(+)
 
 $ git push -u origin patch1
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 342 bytes | 342.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote:
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/werdfgy/lab02/pull/new/patch1
remote:
To https://github.com/werdfgy/lab02.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.
```
4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
``` bash
   $ git ls-remote --heads origin
44de54c3b2e3816b07bc801b0121f050b0775dff        refs/heads/main
66bd9654e9a60446f3018c1d9bfae9ecd5ad1418        refs/heads/patch1
```
5. Создайте pull-request `patch1 -> master`.
   ![[Pasted image 20260318195437.png]]
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
``` bash
   $ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>
#include <string>

int main() {
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия с именем
    std::cout << "Hello world from " << name << std::endl;

    return 0;
}
```
7. **commit**, **push**.
``` bash
   $ git commit -am "add comments to hello_world.cpp"
[patch1 dca6976] add comments to hello_world.cpp
 1 file changed, 3 insertions(+)
$ git push origin patch1
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 549 bytes | 549.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/werdfgy/lab02.git
   66bd965..dca6976  patch1 -> patch1
```
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
   ![[Pasted image 20260318195610.png]]
9. В удалённый репозитории выполните слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
10. Локально выполните **pull**.
```bash
2$ git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
$ git pull origin main
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 910 bytes | 455.00 KiB/s, done.
From https://github.com/werdfgy/lab02
 * branch            main       -> FETCH_HEAD
   44de54c..e0731bb  main       -> origin/main
Updating 44de54c..e0731bb
Fast-forward
 hello_world.cpp | 6 ++++++
 1 file changed, 6 insertions(+)
```
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
``` bash
$ git log --oneline --graph --all
*   e0731bb (HEAD -> main, origin/main) Merge pull request #1 from werdfgy/patch1
|\
| * dca6976 (origin/patch1, patch1) add comments to hello_world.cpp
| * 66bd965 fix code style in patch1
|/
* 44de54c improve hello_world
* e8b6c91 add hello_world with bad code style
* 4e586e6 added README.md
```
12. Удалите локальную ветку `patch1`.
``` bash
$ git branch -d patch1
Deleted branch patch1 (was dca6976).
```
### Part III

[](https://github.com/tp-labs/lab02#part-iii)

**Note:** _Работать продолжайте с теми же репоззиториями, что и в первой части задания._

1. Создайте новую локальную ветку `patch2`.
``` bash
   $ git checkout -b patch2
Switched to a new branch 'patch2'
```
2. Измените _code style_ с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
``` bash
   $ clang-format -style=Mozilla -i hello_world.cpp
```
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
``` bash
   $ git commit -am "apply clang-format Mozilla style to hello_world.cpp"
[patch2 8e53df0] apply clang-format Mozilla style to hello_world.cpp
 1 file changed, 11 insertions(+), 9 deletions(-)
$ git push -u origin patch2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 407 bytes | 407.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote:
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/werdfgy/lab02/pull/new/patch2
remote:
To https://github.com/werdfgy/lab02.git
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'origin/patch2'.
```
4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
   ![[Pasted image 20260318201630.png]]
изменен комментарий в строчке 8
5. Убедитесь, что в pull-request появились _конфликтны_.
![[Pasted image 20260318201749.png]]
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
``` bash
$ git checkout patch2
Already on 'patch2'
Your branch is up to date with 'origin/patch2'.
$ git fetch origin
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 1017 bytes | 203.00 KiB/s, done.
From https://github.com/werdfgy/lab02
   e0731bb..9519621  main       -> origin/main
$  git rebase origin/main
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 8e53df0... apply clang-format Mozilla style to hello_world.cpp
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 8e53df0... apply clang-format Mozilla style to hello_world.cpp
$ nano hello_world.cpp

было
#include <iostream>
#include <string>

int
main()
{
  // Переменная для хранения имени пользователя
  std::string name;

<<<<<<< HEAD
    // Ввод имени пользователя!
    std::cout << "Enter your name: ";
    std::cin >> name;
=======
  // Запрос имени у пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;
>>>>>>> 8e53df0 (apply clang-format Mozilla style to hello_world.cpp)

  // Вывод приветствия с именем
  std::cout << "Hello world from " << name << std::endl;

  return 0;
}
после удаления строчек

#include <iostream>
#include <string>

int
main()
{
  // Переменная для хранения имени пользователя
  std::string name;

    // Ввод имени пользователя!
    std::cout << "Enter your name: ";
    std::cin >> name;

  // Запрос имени у пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Вывод приветствия с именем
  std::cout << "Hello world from " << name << std::endl;

  return 0;
}
git add hello_world.cpp
$ git rebase --continue
[detached HEAD f6b6a71] apply clang-format Mozilla style to hello_world.cpp
 1 file changed, 12 insertions(+), 6 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```
7. Сделайте _force push_ в ветку `patch2`
``` bash
   $ git push --force-with-lease origin patch2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 436 bytes | 436.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/werdfgy/lab02.git
 + 8e53df0...f6b6a71 patch2 -> patch2 (forced update)
```
8. Убедитель, что в pull-request пропали конфликтны.
  ![[Pasted image 20260318203305.png]]
9. Вмержите pull-request `patch2 -> master`.
 ![[Pasted image 20260318203337.png]]

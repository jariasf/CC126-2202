#pragma once

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

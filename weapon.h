#pragma once

enum WeaponType {
    WEAPON_SHORT_RANGE,  // 短射程ブキ (例: シューター)
    WEAPON_MIDDLE_RANGE, // 中射程ブキ (例: ブラスター)
    WEAPON_LONG_RANGE,   // 長射程ブキ (例: チャージャー)
    NUM_WEAPON_TYPES     // 武器の種類数
};

struct WeaponStats {
    WeaponType type;
    float range;         // 射程
    float damage;        // 攻撃力
    float fireRate;      // 発射間隔 (秒/発)
    // 必要に応じて、インク消費量、弾速、スプラッシュ範囲などを追加
};

// 武器データ格納用グローバル配列
extern WeaponStats g_weaponStats[NUM_WEAPON_TYPES];

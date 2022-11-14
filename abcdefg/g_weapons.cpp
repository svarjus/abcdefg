#include "pch.h"

void g::G_SetWeaponData()
{
	if (&PlayerController == nullptr)
		return;

	if (!PlayerController.items)
		return;


	for (int i = 0; i < PlayerController.items->count; i++) {
		const ItemPointer element = PlayerController.items->elements[i];

		if (!PlayerController.items->elements)
			continue;

		if (!&PlayerController.items->elements[i])
			continue;

		element.item->info->damage = v::weapon_damage.evar->arrayValue[i];
		element.item->info->bulletSpread = v::weapon_spread.evar->arrayValue[i];
		element.item->info->maxBulletSpread = v::weapon_spread.evar->arrayValue[i];
		element.item->info->normalSpread = v::weapon_spread.evar->arrayValue[i];
		element.item->info->movementSpreadMultiplier = v::weapon_spread.evar->arrayValue[i] == NULL ? 0 : 1;
		element.item->info->adsSpread = 0;
		element.item->info->adsBulletSpread = 0;
		element.item->info->bulletSpreadDecrease = 0;
		element.item->info->cameraADSBobMultiplier = 1;
		element.item->info->cameraADSBobMultiplier = 1;
		//element.item->info->kickback = 100;
		//element.item->bulletSpread = 360;
		element.item->info->bulletSpread = v::weapon_spread.evar->arrayValue[i];
		element.item->totalAmmo.value = 9999;
		element.item->ammo.value = 9999;
		PlayerController_ptr->bulletSpread = v::weapon_spread.evar->arrayValue[i];

	}

}
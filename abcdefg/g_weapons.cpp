#include "pch.h"

void g::G_SetWeaponData()
{
	if (PlayerController_ptr == nullptr)
		return;

	if (!PlayerController_ptr->items)
		return;



	for (int i = 0; i < PlayerController_ptr->items->count; i++) {
		const ItemPointer* element = &PlayerController_ptr->items->elements[i];

		if (!element)
			continue;

		element->item->info->damage = v::weapon_damage.evar->arrayValue[i];
		element->item->info->bulletSpread = v::weapon_spread.evar->arrayValue[i];
		element->item->info->maxBulletSpread = v::weapon_spread.evar->arrayValue[i];
		element->item->info->normalSpread = v::weapon_spread.evar->arrayValue[i];
		element->item->info->movementSpreadMultiplier = v::weapon_spread.evar->arrayValue[i] == NULL ? 0 : 1;
		element->item->info->adsSpread = 0;
		element->item->info->adsBulletSpread = 0;
		element->item->info->bulletSpreadDecrease = 0;
		element->item->info->cameraADSBobMultiplier = 1;
		element->item->info->cameraADSBobMultiplier = 1;
		//element->item->info->kickback = 100;
		//element->item->bulletSpread = 360;
		element->item->info->bulletSpread = v::weapon_spread.evar->arrayValue[i];
		element->item->totalAmmo.value = 9999;
		element->item->ammo.value = 9999;
		//if (element->item->sway) {

		//	element->item->sway->maxMove = 0.01f;
		//	//element->item->sway->maxRotate= 0;
		//	element->item->sway->moveAmount = 0.01f;
		//	//element->item->sway->rotateSmoothAmount = 0;

		//}
		element->item->info->useDelay = v::weapon_usedelay.evar->arrayValue[i];

		PlayerController_ptr->bulletSpread = v::weapon_spread.evar->arrayValue[i];

		if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
			printf("weapon[%i].item (0x%p)\n", i, element->item);
			printf("weapon[%i].item->info (0x%p)\n", i, element->item->info);

		}

	}

}